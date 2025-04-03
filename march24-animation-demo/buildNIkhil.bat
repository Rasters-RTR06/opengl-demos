 windres Raster.rc -o OGL.o
 gcc Raster.c  -o Raster.exe -mwindows -lopengl32 -lglu32 -luser32 -lgdi32 -lwinmm
