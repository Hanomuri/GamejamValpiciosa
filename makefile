CC=x86_64-w64-mingw32-g++
C=x86_64-w64-mingw32-gcc
cppflags=-ggdb -Wall -Wextra -L./build -l:libraylib.dll -I./raylib/raylib-5.0/src -static -I./include -Wno-write-strings
cppsrc=src/*.cpp
cflags=-ggdb -DPLATFORM_DESKTOP -DSUPPORT_FILEFORMAT_FLAC=1 -fPIC -c -I./external/glfw/include
raysrc=./*.c

all:
	@cp -r resources/ build/
	$(CC) $(cppflags) -o build/main.exe main.cpp $(cppsrc)

raylib: raylib.o
	@echo COMPILING RAYLIB
	@$(C) ./raylib/raylib-5.0/src/*.o -o build/libraylib.dll -lwinmm -lgdi32 -shared

raylib.o:
	@cd ./raylib/raylib-5.0/src && $(C) $(cflags) $(raysrc)
