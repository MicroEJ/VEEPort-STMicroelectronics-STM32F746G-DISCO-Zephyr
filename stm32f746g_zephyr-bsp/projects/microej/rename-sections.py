# Copyright 2021 MicroEJ Corp. All rights reserved.
# This library is provided in source code for use, modification and test, subject to license terms.
# Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

#!/usr/bin/python

import sys
import subprocess

if len(sys.argv) != 3:
    print("This script expects two input arguments, the full path to the objcopy executable and the full path to microejapp object file")
    sys.exit(-1)

subprocess.run([sys.argv[1], \
"--rename-section", "_java_heap=.bss._java_heap", \
"--rename-section", "_java_immortals=.bss._java_immortals", \
"--rename-section", "ICETEA_HEAP=.dtcm_bss.ICETEA_HEAP", \
"--rename-section", ".text.soar=.rodata.soar", \
"--rename-section", ".text.features.installed=.rodata.features.installed", \
"--rename-section", ".shieldedplug=.rodata.shieldedplug", \
sys.argv[2]], capture_output=True)
