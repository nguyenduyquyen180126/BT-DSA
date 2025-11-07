src = crash.c
all: main.a	run
main.a: ${src}
	gcc ${src} -o main.a
run:
	clear
	./main.a
clean:
	clear
	rm -r main.a
debug:
	gcc -g ${src} -o main.a
	gdb main.a