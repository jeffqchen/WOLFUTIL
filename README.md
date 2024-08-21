# WOLFUTIL - MSDOS TSR Utility for Taito Wolf System

This utility implements a watchdog TSR into the DOS timer interrupt, in order to maintain the watchdog state of the Taito Wolf System when running MSDOS.

----------

## Features

### Watchdog Upkeeping through TSR

A TSR procedure is attached to the MSDOS timer interrupt (8) and feeds the watchdog `address 0xCB200` every second in order to keep the system from resetting, as well as maintaining the selected JAMMA video output.

### JAMMA Edge Video Output Switching

By default, the JAMMA video output will be switched to Voodoo. You can change the output manually by using a commandline paramter.
- 0 / s / S - Logo splash screen
- 1 / v / V - Voodoo output
- 2 / t / T - Test grid screen
