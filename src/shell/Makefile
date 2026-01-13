#------------------------------------------------------------
# Makefile for MiniShell project
#
# This Makefile builds a minimal UNIX-like shell that supports
# the execution of a single command using fork() and exec().
#
# Build artifacts are organized as follows:
#   build/out/  -> object files (.o)
#   build/bin/  -> final executable
#------------------------------------------------------------

#------------------------------------------------------------
# Compiler and flags
#------------------------------------------------------------
CC      := gcc

# Enable strict warnings and enforce C99 standard
CFLAGS  := -Wall -Wextra -std=c99 -pedantic

#------------------------------------------------------------
# Directory structure
#------------------------------------------------------------
# Root build directory
BUILD_DIR := build

# Directory for object files
OBJ_DIR   := $(BUILD_DIR)/out

# Directory for final binaries
BIN_DIR   := $(BUILD_DIR)/bin

#------------------------------------------------------------
# Target executable name
#------------------------------------------------------------
TARGET := shell

#------------------------------------------------------------
# Object files
#------------------------------------------------------------
# List of object files required to build the shell
OBJS := \
    $(OBJ_DIR)/shell.o \
    $(OBJ_DIR)/shell_exec.o

#------------------------------------------------------------
# Default target
#------------------------------------------------------------
# Build the shell executable
all: $(BIN_DIR)/$(TARGET)

#------------------------------------------------------------
# Link step
#------------------------------------------------------------
# Link all object files into the final executable
$(BIN_DIR)/$(TARGET): $(OBJS)
	# Ensure binary directory exists
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

#------------------------------------------------------------
# Compilation rules
#------------------------------------------------------------
# Compile shell.c into an object file
$(OBJ_DIR)/shell.o: shell.c shell_exec.h
	# Ensure object directory exists
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c shell.c -o $@

# Compile shell_exec.c into an object file
$(OBJ_DIR)/shell_exec.o: shell_exec.c shell_exec.h
	# Ensure object directory exists
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c shell_exec.c -o $@

#------------------------------------------------------------
# Clean target
#------------------------------------------------------------
# Remove all build artifacts
clean:
	rm -rf $(BUILD_DIR)
