CC = gcc
CFILES = $(wildcard src/*.c)
FLAGS = -fdiagnostics-color=always -pipe -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -Wextra -Wpedantic -std=c99 -O3 -Wno-unused-parameter -Wno-switch

lib:
	git clone https://github.com/andlabs/libui libui
	cd libui && meson setup build --buildtype=release --default-library=shared && ninja -C build
	mv libui/build/meson-out/libui.so.0 libui.so.0
	rm -rf libui

build: $(patsubst %.c,%.c.o,$(CFILES))
	$(CC) -o uigame.exe $^ -Wl,--no-undefined -Wl,--as-needed -Wl,-O1 -Wl,--start-group libui.so.0 -Wl,--end-group '-Wl,-rpath,$$ORIGIN/'

%.c.o: %.c
	$(CC) $(FLAGS) -MD -MQ $< -MF $<.d -o $<.o -c $<

run: uigame.exe
	./uigame.exe

clean:
	rm src/*.o src/*.d *.out *.exe
