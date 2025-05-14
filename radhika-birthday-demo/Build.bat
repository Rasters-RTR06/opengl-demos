cl.exe /c /EHsc raster.c
rc.exe raster.rc
link.exe raster.obj raster.res User32.lib GDI32.lib Kernel32.lib /SUBSYSTEM:WINDOWS
