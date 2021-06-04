..
    Copyright 2020-2021 MicroEJ Corp. All rights reserved.
    This library is provided in source code for use, modification and test, subject to license terms.
    Any modification of the source code will break MicroEJ Corp. warranties on the whole library.

.. _release-notes:
.. |BOARD_NAME| replace:: STM32F746G discovery board
.. |BOARD_REVISION| replace:: A01
.. |PLATFORM_NAME| replace:: STM32F746G Platform
.. |PLATFORM_VER| replace:: 0.1.1
.. |RCP| replace:: MICROEJ SDK
.. |PLATFORM| replace:: MicroEJ Platform
.. |PLATFORMS| replace:: MicroEJ Platforms
.. |SIM| replace:: MicroEJ Simulator
.. |ARCH| replace:: MicroEJ Architecture
.. |CIDE| replace:: MICROEJ SDK
.. |RTOS| replace:: Zephyr RTOS
.. |MANUFACTURER| replace:: STMicroelectronics

.. _README MicroEJ BSP: ./stm32f746g_zephyr-bsp/projects/microej/README.rst
.. _RELEASE NOTES: ./RELEASE_NOTES.rst
.. _CHANGELOG: ./CHANGELOG.rst

.. _release-notes:

========================================================
|PLATFORM| Release Notes for |MANUFACTURER| |BOARD_NAME|
========================================================

Description
===========

This is the release notes of the |PLATFORM| for |BOARD_NAME|.

Versions
========

Platform
--------

|PLATFORM_VER|

Dependencies
------------

This |PLATFORM| contains the following dependencies:

.. list-table::
   :header-rows: 1
   
   * - Dependency Name
     - Version
   * - Architecture (flopi7G26)
     - 7.14.0

Please refer to the |PLATFORM| `module description file <./stm32f746g_zephyr-configuration/module.ivy>`_ 
for more details.

Board Support Package
---------------------

- BSP provider: Zephyr Project
- BSP version: Zephyr v2.5.0

Please refer to the Zephyr Project GitHub git repository
available `here <https://docs.zephyrproject.org/2.5.0/boards/arm/stm32f746g_disco/doc/index.html>`_.

Third Party Software
--------------------

Here is a list of the most important third party software used in the |PLATFORM| BSP implementation:

.. list-table::
   :widths: 3 3 3

   * - RTOS 
     - Zephyr OS
     - 2.5.0

Known issues/limitations
========================

- On Windows, the toolchain doesn't support long path. The build
  directory (named ``target~/``) can be moved closer to the root
  filesystem with the ``target`` property.  For example, set
  ``target=C:/tmp/`` in
  ``stm32f746g_zephyr-configuration/module.properties``.

Platform Memory Layout
======================

Memory Sections
---------------

Each memory section is described in the GCC linker file available
`here <stm32f746g_zephyr-bsp/projects/microej/build/zephyr/linker.cmd>`__ (file generated during the build process).

Memory Layout
-------------

.. list-table::
   :header-rows: 1
   
   * - Section Content
     - Section Source
     - Section Destination
     - Memory Type
   * - MicroEJ Application static
     - ``.bss.soar``
     - ``.bss``
     - internal RAM
   * - MicroEJ Application threads stack blocks 
     - ``.bss.vm.stacks.java``
     - ``.bss``
     - internal RAM
   * - MicroEJ Core Engine internal heap 
     - ``ICETEA_HEAP``
     - ``.dtcm_bss``
     - DTCM
   * - MicroEJ Application heap 
     - ``_java_heap``
     - ``.bss``
     - internal RAM
   * - MicroEJ Application Immortal Heap 
     - ``_java_immortals``
     - ``.bss``
     - internal RAM
   * - MicroEJ Application resources 
     - ``.rodata.resources``
     - ``.rodata``
     - internal Flash
   * - MicroEJ System Applications code and resources 
     - ``.rodata.soar.features``
     - ``.rodata``
     - internal Flash
   * - MicroEJ System Application statics 
     - ``.bss.features.installed``
     - ``.bss``
     - internal RAM
   * - MicroEJ Shielded Plug data 
     - ``.shieldedplug``
     - ``.rodata``
     - internal Flash
   * - MicroEJ Application and Library code 
     - ``.text.soar``
     - ``.rodata``
     - internal Flash

Please also refer to the MicroEJ docs website page available `here
<https://docs.microej.com/en/latest/PlatformDeveloperGuide/coreEngine.html#link>`__
for more details.
