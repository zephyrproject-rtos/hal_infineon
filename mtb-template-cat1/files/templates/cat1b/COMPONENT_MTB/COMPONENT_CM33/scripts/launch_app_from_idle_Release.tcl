#!openocd

# Interface settings
set ENABLE_ACQUIRE 0

## Attach through J-LINK
# source [find interface/jlink.cfg]
## Attach through KitProg3
#source [find interface/kitprog3.cfg]
## Attach through any CMSIS-DAP probe
source [find interface/cmsis-dap.cfg]

transport select swd
source [find target/cyw20829.cfg]

# This instruction changes DAP port to SYS_AP
# Disable polling CM33 core
#cyw208xx.cm33 configure -defer-examine

adapter speed 500
init

# This instruction changes DAP port to SYS_AP
#targets cyw208xx.sysap
targets cyw20829.cm33

# This instruction shows active DAP port
#targets


init
reset init
sleep 200
halt

load_image   $image_bin  0x20004200

set sp [mrw 0x20004200]
set pc [mrw 0x20004204]

reg sp $sp
reg pc $pc
resume

# FP_CTL
mww 0xE0002000 0x00000002
# DCB_DEMCR
mww 0xE000EDFC 0x00000000
# DCB_DHCSR
mww 0xE000EDF0 0xA05F0000

shutdown
