ifeq ($(OS), Windows_NT)
	SLASH = \\
else
	SLASH = /
endif



all: 1

1: Cars.java
	@echo ""
	@echo "Compiling App. \"make run\" to run"
	javac -d build *.java

run:
	java -cp build Cars