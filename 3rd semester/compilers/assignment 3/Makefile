all: build

build: main.l stack.c stack.h
	mkdir -p build
	flex -o build/main.lex.c main.l
	gcc build/main.lex.c stack.c -o build/main -lm -I.

run: build
	./build/main

clean:
	rm -rf build