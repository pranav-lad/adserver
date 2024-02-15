# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -lmemcached -lmysqlclient

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Binary
TARGET = $(BIN_DIR)/ad_server

# Rule to compile all source files
all: $(TARGET)

# Rule to link object files into binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Rule to compile individual source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

# Rule to run the binary
run:
	spawn-fcgi -p 8000 -n $(TARGET)

# Clean rule to remove object files and binary
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
