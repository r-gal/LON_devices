This repository contains source code and PCB for Home Automation peripheral modules.
Code is in Atmel Studio 7.0 format and it is ready to compile and write to Attiny uC.
Important:
1. Fuse bits must be set to high speed
2. Each module must fave unique address. To assume that definition "#define ADR0" in module *.h ( for example SW3.h) must be stepped and code must be recompiled for each module.
