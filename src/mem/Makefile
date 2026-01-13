#------------------------------------------------------------
# Makefile for Memory Management Simulators
# FIFO and LRU share common infrastructure
#------------------------------------------------------------

CC      := gcc
CFLAGS  := -Wall -Wextra -std=c99 -pedantic
LDFLAGS :=

#------------------------------------------------------------
# Build directories
#------------------------------------------------------------
BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/out
BIN_DIR   := $(BUILD_DIR)/bin

#------------------------------------------------------------
# Executables
#------------------------------------------------------------
BINS := $(BIN_DIR)/fifo \
        $(BIN_DIR)/lru

COMMON_OBJS := $(OBJ_DIR)/memory_sim.o

#------------------------------------------------------------
# Default target
#------------------------------------------------------------
all: $(BINS)

#------------------------------------------------------------
# Friendly targets
#------------------------------------------------------------
.PHONY: fifo lru clean

fifo: $(BIN_DIR)/fifo
lru:  $(BIN_DIR)/lru

#------------------------------------------------------------
# Link rules
#------------------------------------------------------------
$(BIN_DIR)/fifo: $(OBJ_DIR)/fifo.o $(COMMON_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/lru: $(OBJ_DIR)/lru.o $(COMMON_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#------------------------------------------------------------
# Compile rules
#------------------------------------------------------------
$(OBJ_DIR)/fifo.o: fifo.c memory_sim.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c fifo.c -o $@

$(OBJ_DIR)/lru.o: lru.c memory_sim.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c lru.c -o $@

$(OBJ_DIR)/memory_sim.o: memory_sim.c memory_sim.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c memory_sim.c -o $@

#------------------------------------------------------------
# Directory creation
#------------------------------------------------------------
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

#------------------------------------------------------------
# Clean
#------------------------------------------------------------
clean:
	rm -rf $(BUILD_DIR)
