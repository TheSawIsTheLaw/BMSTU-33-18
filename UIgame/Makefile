CC = gcc
CFILES = $(wildcard src/*.c)
COMPILE_FLAGS = -fdiagnostics-color=always -pipe -D_FILE_OFFSET_BITS=64 -g -Wall -Winvalid-pch -Wextra -Wpedantic -g -std=c99 -O3 -Wno-unused-parameter -Wno-switch 
LIBNAME = 
LINKING_FLAGS = 

ifeq ($(OS),Windows_NT)
	LIBNAME = libui.dll
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		LIBNAME = libui.so.0
		LINKING_FLAGS =  -Wl,-undefined,error -Wl,--as-needed -Wl,-O1 -Wl,--start-group $(LIBNAME) -Wl,--end-group '-Wl,-rpath,$$ORIGIN/'
	endif
	ifeq ($(UNAME_S),Darwin)
		LIBNAME = libui.A.dylib
		LINKING_FLAGS = -Wl,-dead_strip_dylibs -Wl,-undefined,error -Wl,-headerpad_max_install_names -mmacosx-version-min=10.8 $(LIBNAME) -Wl,-headerpad_max_install_names -Wl,-rpath,@loader_path/
	endif
endif

run: build
	./uigame.exe

lib:
	git clone https://github.com/andlabs/libui libui
	cd libui && meson setup build --buildtype=release --default-library=shared && ninja -C build
	mv libui/build/meson-out/$(LIBNAME) $(LIBNAME)
	rm -rf libui

build: $(patsubst %.c,%.c.o,$(CFILES))
	$(CC) -o uigame.exe $^ $(LINKING_FLAGS)

%.c.o: %.c
	$(CC) $(COMPILE_FLAGS) -MD -MQ $< -MF $<.d -o $<.o -c $<

clean:
	rm src/*.o src/*.d *.out *.exe
