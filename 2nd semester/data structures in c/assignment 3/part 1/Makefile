# Here you set your directories that include your .c files (Example: "PATHS = sources libraries" will include the directories sources and libraries)
PATHS = modules
# Here you set your build directory (don't include slashes). You can leave it empty to build in current directory
BUILD = build
# Here you set your executable's name and it's extension (if needed). You can change it's build directory (Example: "$(BUILD)$(SLASH)main$(EXT)" or "output$(SLASH)main$(EXT)")
OUTPUT = $(BUILD)$(SLASH)main$(EXT)
# Here you choose if the program should automatically be run once compiled (True/False)
AUTORUN = True
# Here you set the output of the run file (leave empty to see the output in the terminal). Only works on Linux
FILEOUTPUT = #$(BUILD)$(SLASH)output.txt
# Here you set whether to run in debug mode (using valgrind)
DEBUG = False


#								   #
#								   #
# Don't modify anything below here #
#								   #
#								   #


# Things that change based on our operating system
ifeq ($(OS), Windows_NT)
	FIND = dir /s /a:-d *.c | findstr /e "\.c"
	CLEAN = del
	SLASH = \\
	EXT = .exe
else
	FIND = find . -name "*.c" -type f -exec basename {} \;
	CLEAN = rm
	SLASH = /
	EXT = 
endif

ifeq ($(AUTORUN), True)
	AUTORUN = run
else
	AUTORUN = 
endif

ifeq ($(FILEOUTPUT),)
	OUTPUTCOMMAND = 
else
	OUTPUTCOMMAND = > $(FILEOUTPUT)
endif

ifeq ($(DEBUG), True)
	DEBUG = valgrind --leak-check=full 
	DEBUGFLAG = -Werror -g
else
	DEBUG = ./
	DEBUGFLAG = 
endif

ifeq ($(BUILD),)
	SLASH = 
endif

INCLUDES = $(addprefix -I, $(PATHS))
VPATH = $(PATHS)

CC = gcc
CFLAGS = -Wall $(DEBUGFLAG) $(INCLUDES)

SRCS = $(filter %.c, $(shell $(FIND)))
OBJS = $(patsubst %.c, $(BUILD)$(SLASH)%.o, $(SRCS)) # Gets .o from every .c in $(SRCS)

default: checkBuildDirectory $(OUTPUT) $(AUTORUN)

# Link .o files and put the output in the build directory
$(OUTPUT):$(OBJS)
	@$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJS)

# Compile .c files into .o files and put them in the build directory (When a source file changes, it is compiled again)
$(BUILD)$(SLASH)%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

checkBuildDirectory: $(BUILD)

$(BUILD):
	@mkdir $(BUILD)

# Run the compiled program
run: $(OUTPUT)
	@$(DEBUG)$(OUTPUT) $(OUTPUTCOMMAND)

# Delete all created files
clean:
	@$(CLEAN) $(OBJS) $(OUTPUT) $(FILEOUTPUT)

# Only works on GNU
mem:
	@memusage -T $(OUTPUT)