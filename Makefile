CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

all: build/opt_cfg

build/opt_cfg: src/basic_blocks_and_optimization.c
	mkdir -p build
	$(CC) $(CFLAGS) src/basic_blocks_and_optimization.c -o build/opt_cfg

run: all
	./build/opt_cfg

clean:
	rm -rf build *.exe
