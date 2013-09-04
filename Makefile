default: hello

hello:
	gcc hello.c -o hello

print_bytes:
	gcc -Wall print_bytes.c -o print_bytes

clean:
	rm hello
	rm print_bytes
