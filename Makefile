CC=gcc
CFLAGS=-g -Wall

default: print_bytes

hello: hello.c
	$(CC) $(CFLAGS) hello.c -o hello

print_bytes: print_bytes.c
	$(CC) $(CFLAGS) print_bytes.c -o print_bytes

clean:
	rm -f hello
	rm -f print_bytes
