# Copyright 2025 Cypress Semiconductor Corporation
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# From https://wiki.tcl-lang.org/page/constants
proc const {name value} {
    uplevel 1 [list set $name $value]
    uplevel 1 [list trace var $name w {error constant} ]
}


set channelName stdout

if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

# Main function
proc main {} {
    const NUM_OF_ARG 7

    if {$::argc != $NUM_OF_ARG} {
        puts stdout "$::argv"
        error "Script requires $NUM_OF_ARG input parameters, got $::argc"
        return 0
    }


    set clockInst [lindex $::argv 0]
    set clockSrc [lindex $::argv 1]
    set clockSrcSourcedByFll [lindex $::argv 2]
    set clockSrcSourcedByImo [lindex $::argv 3]
    set pllIsBypassed [lindex $::argv 4]
    set clockSrcFracEn [lindex $::argv 5]
    set clockSrcSscgEn [lindex $::argv 6]

    return [lookup_max_freq $clockInst $clockSrc $clockSrcSourcedByFll $clockSrcSourcedByImo $pllIsBypassed $clockSrcFracEn $clockSrcSscgEn]
}

proc lookup_max_freq {clockInst clockSrc clockSrcSourcedByFll clockSrcSourcedByImo pllIsBypassed clockSrcFracEn clockSrcSscgEn} {
    # Max clock values, per root clock.
    # The first row in each sub-table is for the first PLL source, the second row is for the second PLL source.
    #   - So the second row only applies to the HfClks that have multiple PLL sources with "guaranteed mappings".
    # Derived from Table 26-19 (pg 153 attow) in the CYT4DN Datasheet.
    #   [0]     [1]     [2]         [3]          [4]            [5]         [6]             [7]          [8]
    #   FLL+ECO FLL+IMO PLL+ECO+Int PLL+ECO+SSCG PLL+ECO+Frac   PLL+IMO+Int PLL+IMO+SSCG    PLL+IMO+Frac DefaultMax
    const HfClkTable {
        {{100   100     200         0            0              191         0               0            200}
         {0     0       0           0            0              0           0               0            0}}
        {{100   100     320         313          316            306         300             303          320}
         {0     0       0           0            0              0           0               0            0}}
        {{100   97      100         0            0              95          0               0            100}
         {0     0       0           0            0              0           0               0            0}}
        {{100   97      100         0            0              95          0               0            100}
         {0     0       0           0            0              0           0               0            0}}
        {{50    48      50          0            0              47          0               0            50 }
         {0     0       0           0            0              0           0               0            0}}
        {{100   100     200         196          198            191         187             189          200}
         {0     0       0           0            0              0           0               0            0}}
        {{100   100     200         196          198            191         187             189          200}
         {0     0       0           0            0              0           0               0            0}}
        {{100   100     200         196          198            191         187             189          200}
         {0     0       0           0            0              0           0               0            0}}
        {{100   100     333         326          329            318         312             315          370}
         {100   100     333         362          366            318         312             315          370}}
        {{100   100     333         326          329            318         312             315          370}
         {100   100     333         362          366            318         312             315          370}}
        {{100   100     254         250          252            243         239             241          254}
         {0     0       0           0            0              0           0               0            0}}
        {{100   100     224         220          222            214         210             212          224}
         {100   100     200         0            0              191         0               0            224}}
        {{100   100     224         220          222            214         210             212          224}
         {100   100     200         0            0              191         0               0            224}}
    }

    # Get the row with maximum frequencies for the clockInst passed in from the personality.  Default to the first row within
    # the resulting two row table.
    set hfclk_rows [lindex $HfClkTable $clockInst]
    set hfclk_row [lindex $hfclk_rows 0]

    # Check if this is a row with multiple PLL sources, and if the second PLL is in use, select the second row.
    switch $clockInst {
        8 {
            if {$clockSrc == "pll400m\[2]"} {
                set hfclk_row [lindex $hfclk_rows 1]
            }
        }
        9 {
            if {$clockSrc == "pll400m\[2]"} {
                set hfclk_row [lindex $hfclk_rows 1]
            }
        }
        11 {
            if {$clockSrc == "pll\[2]"} {
                set hfclk_row [lindex $hfclk_rows 1]
            }
        }
        12 {
            if {$clockSrc == "pll\[2]"} {
                set hfclk_row [lindex $hfclk_rows 1]
            }
        }
    }

    # Create the index to the correct maximum frequency in the table.
    if {$clockSrcSourcedByFll} {
        if ($clockSrcSourcedByImo) {
            set idx 1
        } else {
            set idx 0
        }
    } else {
        # FLL maxes are the first two columns in the table.  PLLs start at index 2.
        set idx 2
        # If the clock source is sourced by IMO, then move over three more columns.
        if ($clockSrcSourcedByImo) {
            set idx [expr {$idx + 3}]
        }

        # If the clock source is Integer, then the idx is already at the right column.
        # If SSCG or Fractional are enabled, then we need to adjust the index.
        if ($clockSrcSscgEn) {
            set idx [expr {$idx + 1}]
        } elseif ($clockSrcFracEn) {
            set idx [expr {$idx + 2}]
        }
    }

    # Get the maximum frequency from the table and convert it to Hz.
    set retval [lindex $hfclk_row $idx]
    set retval [expr {int($retval) * 1000000}]

    puts $::channelName "$retval"
    return $retval
}

#tclsh hfclk_t2g2d6m_maxclk.tcl 8 pll400m[1] false false false false false
#lookup_max_freq 0 0 true false false false false true
main
