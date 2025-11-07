src = main.c
all: main.a run
main.a: ${src} *.c
	gcc Array.c ${src} -o main.a
run:
	./main.a
clean:
	rm -r *.a
debug:
	gcc -g Array.c ${src} -o main.a
	gdb main.a
test_merge_sort: 
	gcc Array.c test_merge_sort_.c -o test.a
	./test.a
test_quick_sort:
	gcc Array.c test_quick_sort_.c -o test.a
	./test.a