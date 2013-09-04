default: hello

hello: hello.c
	gcc hello.c -o hello

print_bytes: print_bytes.c
	gcc -Wall print_bytes.c -o print_bytes

clean:
	rm -f hello
	rm -f print_bytes
