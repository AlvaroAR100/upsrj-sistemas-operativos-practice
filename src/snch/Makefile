#------------------------------------------------------------
# Makefile for Bridge Synchronization Exercise
#
# This project demonstrates synchronization using mutexes
# and semaphores through the classic "monkeys crossing a bridge"
# problem.
#
# Build artifacts:
#   build/out/  -> object files (.o)
#   build/bin/  -> executable
#------------------------------------------------------------

#------------------------------------------------------------
# Compiler and flags
#------------------------------------------------------------
CC := gcc

# Enable warnings and enforce C99 standard
CFLAGS := -Wall -Wextra -std=c99 -pedantic

# Link with pthread library
LDFLAGS := -pthread

#------------------------------------------------------------
# Directory structure
#------------------------------------------------------------
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/out
BIN_DIR   := $(BUILD_DIR)/bin

#------------------------------------------------------------
# Target executable
#------------------------------------------------------------
TARGET := bridge

#------------------------------------------------------------
# Object files
#------------------------------------------------------------
OBJS := \
    $(OBJ_DIR)/main.o \
    $(OBJ_DIR)/bridge.o

#------------------------------------------------------------
# Default target
#------------------------------------------------------------
all: $(BIN_DIR)/$(TARGET)

#------------------------------------------------------------
# Link step
#------------------------------------------------------------
$(BIN_DIR)/$(TARGET): $(OBJS)
	# Ensure binary directory exists
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#------------------------------------------------------------
# Compilation rules
#------------------------------------------------------------
# Compile main.c
$(OBJ_DIR)/main.o: main.c bridge.h
	# Ensure object directory exists
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c main.c -o $@

# Compile bridge.c
$(OBJ_DIR)/bridge.o: bridge.c bridge.h
	# Ensure object directory exists
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c bridge.c -o $@

#------------------------------------------------------------
# Clean target
#------------------------------------------------------------
clean:
	rm -rf $(BUILD_DIR)
