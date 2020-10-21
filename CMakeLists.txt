# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.18.2 FATAL_ERROR)

# TODO: @mbed-os-tools MBED_ROOT and MBED_CONFIG_PATH should probably come from mbedtools
set(MBED_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
set(MBED_CONFIG_PATH ${CMAKE_CURRENT_SOURCE_DIR}/.mbedbuild CACHE INTERNAL "")
set(APP_TARGET mbed-os-example-blinky)

include(${MBED_CONFIG_PATH}/mbed_config.cmake)

# Set default toolchain file
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${MBED_ROOT}/tools/cmake/toolchain.cmake" CACHE INTERNAL "")
endif()

# Toolchain setup
include(${MBED_ROOT}/tools/cmake/toolchains/${MBED_TOOLCHAIN}.cmake)
enable_language(C CXX ASM)

add_subdirectory(${MBED_ROOT})

add_executable(${APP_TARGET})

mbed_configure_app_target(${APP_TARGET})

mbed_set_mbed_target_linker_script(${APP_TARGET})

project(${APP_TARGET})

target_sources(${APP_TARGET}
    PRIVATE
        main.cpp
)

target_link_libraries(${APP_TARGET}
    PRIVATE
        mbed-os
    INTERFACE
        mbed-os-rtos
)

mbed_generate_bin_hex(${APP_TARGET})

option(VERBOSE_BUILD "Have a verbose build process")
if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()
