# SPDX-License-Identifier: MIT

zephyr_include_directories(.)

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_AX12 motor_ax12.c)