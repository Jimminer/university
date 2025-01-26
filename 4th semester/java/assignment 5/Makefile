ifeq ($(OS), Windows_NT)
	SLASH = \\
	PATH_SEPARATOR = ;
else
	SLASH = /
	PATH_SEPARATOR = :
endif



all: 1

1: MainWindow.java
	@echo ""
	@echo "Compiling App. \"make run\" to run"
	javac -cp libs -d build *.java

run:
	java -cp .$(PATH_SEPARATOR)libs$(SLASH)*$(PATH_SEPARATOR)build MainWindow