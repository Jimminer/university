ifeq ($(OS), Windows_NT)
	SLASH = \\
else
	SLASH = /
endif



all: 1

1: Transport.java Vehicle.java Engine.java ControlSystem.java
	@echo ""
	@echo "Compiling App. \"make run\" to run"
	javac -d build *.java

run:
	java -cp build Transport