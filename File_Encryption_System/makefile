CC = gcc
CFLAGS = -Wall -g -Iinclude        # Include path for system.h
LDFLAGS = -lcrypto
OBJDIR = obj
BINDIR = bin
TARGET = program

SRC_FILES = src/task0.c src/task1.c src/task2.c src/task3.c \
            src/task4.c src/task5.c src/task6.c main.c

OBJ_FILES = $(SRC_FILES:src/%.c=obj/%.o)

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Default target
all: $(BINDIR)/$(TARGET)

# Compile each .c file to .o
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create executable
$(BINDIR)/$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(BINDIR)/$(TARGET) $(LDFLAGS)

# Clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean