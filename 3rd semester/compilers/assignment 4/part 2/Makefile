ifeq ($(OS), Windows_NT)
	EXT = .exe
	SLASH = \\
else
	EXT = 
	SLASH = /
endif

all: build

build: lex.l yacc.y
	@echo ""
	@echo "Building part 2"
	mkdir -p build
	yacc -d -v -o build$(SLASH)y.tab.c yacc.y
	flex -o build$(SLASH)lex.yy.c lex.l
	gcc build$(SLASH)lex.yy.c build$(SLASH)y.tab.c -o build$(SLASH)main$(EXT) -lm

clean:
	@echo ""
	@echo "Cleaning up"
	rm -rf build

run: build
	./build/main$(EXT)