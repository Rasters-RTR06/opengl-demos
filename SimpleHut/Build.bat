cl.exe /c /EHsc /I c:\freeglut\include SimpleHut.c

link.exe SimpleHut.obj /LIBPATH:C:\freeglut\lib\x64 freeglut.lib /SUBSYSTEM:CONSOLE

SimpleHut.exe