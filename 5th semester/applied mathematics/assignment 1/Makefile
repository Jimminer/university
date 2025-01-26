ifeq ($(OS), Windows_NT)
	EXT = .exe
	SLASH = \\
else
	EXT = 
	SLASH = /
endif

all: build

build: main.c funcs.c
	@mkdir -p build
	@gcc main.c funcs.c -lm -o build$(SLASH)main$(EXT)

run:
	@.$(SLASH)build$(SLASH)main

texbuild:
	@pdflatex report.tex