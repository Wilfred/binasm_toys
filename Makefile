default: hello

hello:
	gcc hello.c -o hello

print_bytes:
	gcc -Wall print_bytes.c -o print_bytes

clean:
	rm -f hello
	rm -f print_bytes
