CC      = gcc
CFLAGS  = -Wall -Wextra -O3 -Iinclude

SRCROOT = src
OBJROOT = obj
BINROOT = bin

TARGET  = $(BINROOT)/main

# All C sources (recursive)
SRCFILES := $(shell find $(SRCROOT) -name "*.c")

# Mirror src → obj directory structure
OBJFILES := $(SRCFILES:$(SRCROOT)/%.c=$(OBJROOT)/%.o)

all: $(TARGET)

# Link
$(TARGET): $(OBJFILES)
	@mkdir -p $(BINROOT)
	$(CC) $(CFLAGS) $^ -o $@

# Compile (structure-preserving)
$(OBJROOT)/%.o: $(SRCROOT)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJROOT) $(BINROOT)

.PHONY: all clean