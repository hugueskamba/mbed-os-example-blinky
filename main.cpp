/* mbed Microcontroller Library
 * Copyright (c) 2018-2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#if !MBED_BARE_METAL
extern void blinky_rtos();
#else
extern void blinky_bare_metal();
#endif // !MBED_BARE_METAL

int main()
{
#ifndef MBED_BARE_METAL
    blinky_rtos();
#else
    blinky_bare_metal();
#endif // !MBED_BARE_METAL
}
