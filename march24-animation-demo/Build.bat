cl.exe /c /EHsc Raster.c
rc.exe Raster.rc
link.exe Raster.obj Raster.res User32.lib GDI32.lib Kernel32.lib glu32.lib Winmm.lib /SUBSYSTEM:WINDOWS
Raster.exe