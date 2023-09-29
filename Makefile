.PHONY: all build clean

all: build run

build:
	mkdir -p build
	cd build && cmake ..
	make -C build

run:
	GSETTINGS_SCHEMA_DIR=./build ./build/my_app

clean:
	rm -rf build

