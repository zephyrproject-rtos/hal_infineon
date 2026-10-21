#!/usr/bin/python3

"""
Copyright (c) 2020 Cypress Semiconductor Corporation
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

import os
import platform
import sys, argparse
import subprocess
import json
import shutil
from cysecuretools import CySecureTools
from intelhex import IntelHex

# This script signs an output hex file using cysecuretools based
# on the input parameters
# Example Usage:
# psoc64_postbuild.py --core CM4 \
# --secure-boot-stage single \
# --policy policy_single_CM0_CM4 \
# --target cyb06xxa \
# --toolchain-path ModusToolbox/tools_2.0/gcc-7.2.1 \
# --toolchain GCC_ARM \
# --build-dir Hello_World/build/CY8CKIT-064B0S2-4343W/Debug \
# --app-name mtb-example-psoc6-hello-world \
# --cm0-app-path ./libs/psoc6cm0p/COMPONENT_CM0P_SECURE \
# --cm0-app-name psoc6_02_cm0p_secure


def myargs(argv):
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument('-h', '--help',
                        dest='show_help',
                        action='help',
                        help='Print this help message and exit')

    parser.add_argument('--policy-path',
                        dest='policy_path',
                        action='store',
                        type=str,
                        help="Path to policy file",
                        required=False)

    parser.add_argument('-p', '--policy',
                        dest='policy_file',
                        action='store',
                        type=str,
                        help="Device policy file",
                        required=True)

    parser.add_argument('-t', '--target',
                        dest='target_name',
                        action='store',
                        type=str,
                        help="Target name according to cysecuretools",
                        required=True)

    parser.add_argument('--toolchain-path',
                        dest='toolchain_path',
                        action='store',
                        type=str,
                        help="Path to the toolchain tools to use for .hex file generation",
                        required=True)

    parser.add_argument('--toolchain',
                        dest='toolchain',
                        action='store',
                        type=str,
                        help="Actual toolchain that was used to build the application",
                        required=True)

    parser.add_argument('-b', '--build-dir',
                        dest='build_dir',
                        action='store',
                        type=str,
                        help="Path of build directory to find application hex files",
                        required=True)

    parser.add_argument('-a', '--app-name',
                        dest='app_name',
                        action='store',
                        type=str,
                        help="Name of application",
                        required=True)

    parser.add_argument('-c', '--cm0-app-path',
                        dest='cm0_app_path',
                        action='store',
                        type=str,
                        help="Path where CM0 hex file is located",
                        required=False)

    parser.add_argument('--cm0-app-name',
                        dest='cm0_app_name',
                        action='store',
                        type=str,
                        help="Name of CM0 hex file",
                        required=False)

    parser.add_argument('--core',
                        dest='core',
                        action='store',
                        type=str,
                        help="Building for CM0/CM4",
                        required=True)

    parser.add_argument('-s', '--secure-boot-stage',
                        dest='secure_boot_stage',
                        action='store',
                        type=str,
                        help="Single/Multi stage scheme",
                        required=True)


    options = parser.parse_args(argv)
    return options

def exec_shell_command(cmd):
    print("Executing command: {}".format(' '.join(cmd)))
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                              stderr=subprocess.STDOUT)
    for line in iter(p.stdout.readline, b''):
        print("{}".format(line.decode('utf-8')), end='')
    p.stdout.close()
    ret = p.wait()
    print("Command completed (ret={})".format(ret))
    return ret

def main(argv):

    options = myargs(argv)
    print("options: {}".format(options))

    if not options.policy_path:
        options.policy_path = 'policy'

    tools = CySecureTools(options.target_name, options.policy_path + "/" + options.policy_file +'.json')
    if (options.toolchain == 'ARM'):
        fromelf_cmd = options.toolchain_path + "/bin/fromelf"
        app_elf_file = options.build_dir + "/" + options.app_name + ".elf"
        fromelf_result_dir = options.build_dir + "/" + "fromelf_result"
        # Check if gcc tools path is valid
        if (os.path.isdir(options.toolchain_path) == False):
            print("ERROR: 'ARM Compiler' tools folder not found in path: {}".format(options.toolchain_path))
            exit(-1)

        # Check if elf is valid
        if (os.path.isfile(app_elf_file) == False):
            print("ERROR: ELF file not found in path: {}\r\n".format(app_elf_file))
            exit(-1)

        # Split elf file into sections
        shell_cmd = [ fromelf_cmd, '--i32', '--output=' + fromelf_result_dir, app_elf_file ]
        ret = exec_shell_command(shell_cmd)
        if (ret != 0):
            exit(ret)

        em_eeprom_hex = fromelf_result_dir + "/" + ".cy_em_eeprom"
        app_hex_path = options.build_dir + '/' + options.app_name + '.hex'
        if (os.path.isfile(em_eeprom_hex) == True):
            sections_list = [f for f in os.listdir(fromelf_result_dir) if os.path.isfile(os.path.join(fromelf_result_dir, f))]
            sections_list.remove('.cy_em_eeprom')
            flash = IntelHex()

            for section in sections_list:
                sect = IntelHex(fromelf_result_dir + "/" + section)
                flash.merge(sect, overlap='replace')

            flash.write_hex_file(app_hex_path, False)

        CM0_app_src_path = options.cm0_app_path + '/' + options.cm0_app_name + '.hex'
        CM0_app_dst_path = options.build_dir + '/' + options.cm0_app_name + '.hex'

        # CySecureTools Image ID for CM4 Applications is
        # 1) 1 for single-stage,
        # 2) 16 in case of multi-stage,
        # Image ID for CM0 Applications is always 1
        if (options.core == "CM4"):
            if (options.secure_boot_stage == "single"):
                # Sign CM4 image
                tools.sign_image(app_hex_path, 1)
            else:
                # Sign CM4 image
                tools.sign_image(app_hex_path, 16)
                # Make a copy of CM0P app image in build folder
                shutil.copy2(CM0_app_src_path, CM0_app_dst_path)

                # Sign CM0 image
                tools.sign_image(CM0_app_dst_path, 1)

                # Merge CM0, CM4 into a single hex file
                ihex = IntelHex()
                ihex.padding = 0x00
                ihex.loadfile(app_hex_path, 'hex'); \
                        ihex.merge(IntelHex(CM0_app_dst_path), 'ignore'); \
                        ihex.write_hex_file(app_hex_path, write_start_addr=False, byte_count=16)
        else:
            tools.sign_image(app_hex_path, 1)

        if (os.path.isfile(em_eeprom_hex) == True):
            # Add emulated EEPROM Section back
            flash = IntelHex(app_hex_path)
            eeprom = IntelHex(em_eeprom_hex)
            flash.merge(eeprom)
            flash.write_hex_file(app_hex_path, False)
    else:
        gcc_objcopy_eabi_cmd = options.toolchain_path + '/bin/arm-none-eabi-objcopy'
        app_elf_file = options.build_dir + "/" + options.app_name +".elf"

        # Check if gcc tools path is valid
        if(os.path.isdir(options.toolchain_path)==False):
            print("ERROR: GCC tools folder not found in path: {}".format(options.toolchain_path))
            exit(-1)

        # Check if elf is valid
        if(os.path.isfile(app_elf_file) == False):
            print("ERROR: ELF file not found in path: {}\r\n".format(app_elf_file))
            exit(-1)

        # Strip away emulated EEPROM section from hex file before signing
        shell_cmd = [ gcc_objcopy_eabi_cmd, '-R', '.cy_em_eeprom', '-O', 'ihex', app_elf_file, options.build_dir + "/" + options.app_name + ".hex" ]
        ret = exec_shell_command(shell_cmd)
        if(ret != 0):
            exit(ret)

        # Store emulated eeprom section in a seperate hex file
        shell_cmd = [ gcc_objcopy_eabi_cmd, '-j', '.cy_em_eeprom', '-O', 'ihex', options.build_dir + "/" + options.app_name + ".elf", options.build_dir + "/em_eeprom.hex" ]
        ret = exec_shell_command(shell_cmd)
        if(ret != 0):
            exit(ret)

        app_hex_path = options.build_dir + '/' + options.app_name + '.hex'
        CM0_app_src_path = options.cm0_app_path + '/' + options.cm0_app_name +  '.hex'
        CM0_app_dst_path = options.build_dir + '/' + options.cm0_app_name + '.hex'

        # CySecureTools Image ID for CM4 Applications is
        # 1) 1 for single-stage,
        # 2) 16 in case of multi-stage,
        # Image ID for CM0 Applications is always 1
        if(options.core == "CM4"):
            if(options.secure_boot_stage == "single"):
                # Sign CM4 image
                tools.sign_image(app_hex_path,1)
            else:
                # Sign CM4 image
                tools.sign_image(app_hex_path,16)
                # Make a copy of CM0P app image in build folder
                shutil.copy2(CM0_app_src_path, CM0_app_dst_path)

                # Sign CM0 image
                tools.sign_image(CM0_app_dst_path,1)

                # Merge CM0, CM4 into a single hex file
                ihex = IntelHex()
                ihex.padding = 0x00
                ihex.loadfile(app_hex_path, 'hex'); \
                ihex.merge(IntelHex(CM0_app_dst_path), 'ignore'); \
                ihex.write_hex_file(app_hex_path, write_start_addr=False, byte_count=16)
        else:
            tools.sign_image(app_hex_path,1)

        # Add emulated EEPROM Section back
        flash = IntelHex(app_hex_path)
        eeprom = IntelHex(options.build_dir + "/em_eeprom.hex")
        flash.merge(eeprom)
        flash.write_hex_file(app_hex_path, False)

    exit(0)

if __name__ == "__main__":
    main(sys.argv[1:])
