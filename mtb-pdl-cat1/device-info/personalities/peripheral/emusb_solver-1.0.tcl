# Copyright 2022 Cypress Semiconductor Corporation
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

# Constant
const REQ_PERI_CLOCK_ACCURACY 0.0025
const EXPECTED_FREQ_MAX 100250
const EXPECTED_FREQ_MIN 99750

# Name of returned parameters
const UPPER_DIV "upperDiv"
const LOWER_DIV "lowerDiv"
const BEST_DIV "bestDiv"
const RESULT "result"

# Result constant
const THE_DIV_VALUE_IS_FOUND 0
const THE_DIV_VALUE_IS_NOT_FOUND 1
const RESULT_BAD_ACCURACY 2

# Send data to personality
proc output_results {upper_div lower_div best_div result} {
    puts $::channelName "param:$::UPPER_DIV=$upper_div"
    puts $::channelName "param:$::LOWER_DIV=$lower_div"
    puts $::channelName "param:$::BEST_DIV=$best_div"
    puts $::channelName "param:$::RESULT=$result"
}

# The number of input parameters
const NUM_OF_ARG 2

# Main function
proc main {} {
    if {$::argc != $::NUM_OF_ARG} {
        error "Script requires two input parameters"
        return 0
    }

    set peri_clock_freq [lindex $::argv 0]
    set peri_clock_accuracy [lindex $::argv 1]

    # Set default statuses
    set upper_div 0
    set lower_div 0
    set best_div  0
    set result $::THE_DIV_VALUE_IS_FOUND

    # Check accuracy
    if {$peri_clock_accuracy > $::REQ_PERI_CLOCK_ACCURACY} {
        set result $::RESULT_BAD_ACCURACY
    } else {

        set upper_freq_limit_real [expr {$::EXPECTED_FREQ_MAX / (1 + $peri_clock_accuracy)}]
        set lower_freq_limit_real [expr {$::EXPECTED_FREQ_MIN / (1 - $peri_clock_accuracy)}]

        set upper_div [expr {floor($peri_clock_freq / $lower_freq_limit_real)}]
        set lower_div [expr {ceil($peri_clock_freq / $upper_freq_limit_real)}]

        if {$lower_div > $upper_div} {
            set result $::THE_DIV_VALUE_IS_NOT_FOUND
        } else {
            set best_div [expr {$lower_div + round(($upper_div - $lower_div) / 2)}]
        }
    }

    if {$result != $::THE_DIV_VALUE_IS_FOUND} {
        set upper_div 0
        set lower_div 0
        set best_div  0
    }

    output_results $upper_div $lower_div $best_div $result
}


# Select output methods
set channelName stdout
if {[chan names ModusToolbox] eq "ModusToolbox"} {
    set channelName ModusToolbox
}

# Start calculation
main
