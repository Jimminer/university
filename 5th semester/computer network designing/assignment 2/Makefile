ifeq ($(OS), Windows_NT)
	EXT = .exe
	SLASH = \\
	CLEAN = del /q
else
	EXT = 
	SLASH = /
	CLEAN = rm -rf
endif

all: build

build: main.c
	@mkdir -p build
	@gcc main.c -o build$(SLASH)main$(EXT)

run:
	@.$(SLASH)build$(SLASH)main$(EXT)

clean:
	@$(CLEAN) build