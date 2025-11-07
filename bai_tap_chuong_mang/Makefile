src = array_test.c
all: test.a run
test.a: ${src} *.c
	gcc Array.c ${src} -o test.a
run:
	./test.a
clean:
	rm -r test.a
debug:
	gcc -g Array.c ${src} -o test.a
	gdb test.a