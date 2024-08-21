# WOLFUTIL - MSDOS TSR Utility for Taito Wolf System

This utility allows you to switch video output on the JAMMA edge of the Taito Wolf System, so you can run MSDOS games supporting the onboard 3Dfx Voodoo.

----------

## Features

### JAMMA Edge Video Output Switching

By default, the JAMMA video output will be switched to Voodoo. You can change the output manually by using a commandline paramter.
- `0 / s / S` - Logo splash screen
- `1 / v / V` - Voodoo output
- `2 / t / T` - Test grid screen

### Watchdog Upkeeping TSR

A TSR procedure is attached to the MSDOS timer interrupt (8) and feeds the watchdog `address 0xCB200` every second in order to keep the system from resetting, as well as maintaining the selected JAMMA video output.

TSR will not load if the timer interrupt is not at its default value, in order to prevent repeatedly loading itself or breaking other TSR on the timer interrupt.

----------

## Usage

Add the executable to `AUTOEXEC.BAT` so it loads as soon as possible during system boot.

----------

## Compiling

This utility is developed in Borland Turbo C++ 3.0.
