.. 
	Copyright 2019-2021 MicroEJ Corp. All rights reserved.
	This library is provided in source code for use, modification and test, subject to license terms.
	Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

.. |BOARD_NAME| replace:: STM32F746G discovery
.. |BOARD_REVISION| replace:: A01
.. |PLATFORM_NAME| replace:: STM32F746G Platform
.. |PLATFORM_VER| replace:: 0.1.0
.. |RCP| replace:: MICROEJ SDK
.. |PLATFORM| replace:: MicroEJ Platform
.. |PLATFORMS| replace:: MicroEJ Platforms
.. |SIM| replace:: MicroEJ Simulator
.. |ARCH| replace:: MicroEJ Architecture
.. |CIDE| replace:: MICROEJ SDK
.. |RTOS| replace:: Zephyr RTOS
.. |MANUFACTURER| replace:: STMicroelectronics

.. _README: ./../../../README.rst
.. _RELEASE NOTES: ./../../../RELEASE_NOTES.rst
.. _CHANGELOG: ./../../../CHANGELOG.rst

================
|BOARD_NAME| BSP
================

This project contains the BSP sources of the |PLATFORM| for the
|BOARD_NAME|.

This document does not describe how to setup the |PLATFORM|.  Please
refer to the `README`_ for that.

Build & Flash Scripts
=====================

The scripts to build and flash the BSP are located under ``projects/microej/scripts/``.
All scripts are provided in bash (.sh) and batch (.bat) implementation, select the variant supported by your OS.

- The ``set_local_env`` script is used to set environment variables required for the build/flash process.
  
- The ``set_project_env`` script is used to set default environment variables required for the build/flash process.
  It calls the ``set_local_env`` script, if present, to get the user-defined values.
  
- The ``build`` script is used to compile and link the BSP with a
  MicroEJ Application to produce a MicroEJ Firmware
  (``microej.out`` located under ``projects/microej/scripts/`` if the compilation was successful) that can be flashed onto the device. 
  It calls the ``set_project_env`` script to set the relevant variables.

- The ``run`` script is used to flash a MicroEJ Firmware
  (``application.out``) onto the device. It calls the ``set_project_env`` script to set the relevant variables.

The following environment variables are customizable: 

- ``ZEPHYR_BASE``: The path to the zephyr installation directory.
- ``GNUARMEMB_TOOLCHAIN_PATH``: The path to the GNU ARM compilation toolchain.
- ``OPENOCD_EXEC_PATH``: The path to the openocd executable.
- ``ZEPHYR_BUILD_DIR``: The path to the zephyr application build directory.

The environment variables can be defined globally by the user or in
the ``set_local_env`` scripts.  When the build/flash scripts
are executed, the ``set_local_env`` script is executed if it exists.
Configure these files to customize the environment locally.

Debugging with the |BOARD_NAME|
===============================

Linux:

.. code-block:: sh

      $ west debug -d "$ZEPHYR_BUILD_DIR" --openocd="$OPENOCD_EXEC_PATH/openocd"
	  
Windows:

.. code-block:: sh

      $ west debug -d "%ZEPHYR_BUILD_DIR%" --openocd="%OPENOCD_EXEC_PATH%\openocd.exe"
