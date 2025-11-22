CC = g++
DB = gdb
CFLAGS = -Wall
all: clean test.a run
run:
	./*.a
test.a: test.cpp
	$(CC) -g $(CFLAGS) $^ -o $@
clean:
	rm -rf *.a
debug:
	$(DB) *.a