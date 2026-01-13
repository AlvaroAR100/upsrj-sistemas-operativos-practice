#------------------------------------------------------------
# Makefile for Scheduler Simulators
# FCFS, RR and SJF share common infrastructure
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
BINS := $(BIN_DIR)/fcfs \
        $(BIN_DIR)/rr   \
        $(BIN_DIR)/sjf

COMMON_OBJS := $(OBJ_DIR)/process.o

#------------------------------------------------------------
# Default target
#------------------------------------------------------------
all: $(BINS)

#------------------------------------------------------------
# Friendly targets
#------------------------------------------------------------
.PHONY: fcfs rr sjf clean

fcfs: $(BIN_DIR)/fcfs
rr:   $(BIN_DIR)/rr
sjf:  $(BIN_DIR)/sjf

#------------------------------------------------------------
# Link rules
#------------------------------------------------------------
$(BIN_DIR)/fcfs: $(OBJ_DIR)/fcfs.o $(COMMON_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/rr: $(OBJ_DIR)/rr.o $(COMMON_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/sjf: $(OBJ_DIR)/sjf.o $(COMMON_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#------------------------------------------------------------
# Compile rules
#------------------------------------------------------------
$(OBJ_DIR)/fcfs.o: fcfs.c process.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c fcfs.c -o $@

$(OBJ_DIR)/rr.o: rr.c process.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c rr.c -o $@

$(OBJ_DIR)/sjf.o: sjf.c process.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c sjf.c -o $@

$(OBJ_DIR)/process.o: process.c process.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c process.c -o $@

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