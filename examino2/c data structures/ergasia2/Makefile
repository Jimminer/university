# Changes the clean command according to our operating system
ifeq ($(OS), Windows_NT)
	CLEAN = rmdir /q /s
else
	CLEAN = rm -rf
endif

INCLUDES = -Imodules
VPATH = modules
BUILD = build
OUTPUT = main

CC = gcc
CFLAGS = -Wall $(INCLUDES)

SRCS = main.c dataStructures.c
OBJS = $(patsubst %.c, $(BUILD)/%.o, $(SRCS)) # Gets .o from every .c given in $(SRCS)

default: checkBuildDir $(OUTPUT)
	@$(BUILD)/$(OUTPUT)

# Link .o files and put the output in the build directory
$(OUTPUT):$(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(BUILD)/$(OUTPUT) $(OBJS)

# Compile .c files into .o files and put them in the build directory (When a source file changes, it is compiled again)
$(BUILD)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Check if the build directory exists. If not, create it
checkBuildDir: $(BUILD)

$(BUILD):
	@mkdir $(BUILD)

# Delete the build directory including it's files
clean:
	@$(CLEAN) $(BUILD)