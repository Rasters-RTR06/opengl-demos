#!/bin/bash
#set -e


x86_64-w64-mingw32-windres Raster.rc -o Raster.o
x86_64-w64-mingw32-gcc Raster.c -o Raster.exe -mwindows -lopengl32 -luser32 -lgdi32
