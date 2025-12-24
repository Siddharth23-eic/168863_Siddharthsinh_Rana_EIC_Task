CC      = gcc
CFLAGS  = -Wall -Wextra -O3 -Iinclude
LFLAGS  = -lm

OBJDIR  = obj
BINDIR  = bin
TARGET  = $(BINDIR)/main

# -------------------------------------------------
# Source discovery
# -------------------------------------------------
SRCFILES := \
    $(wildcard src/*.c) \
    $(wildcard src/*/*.c) \
    $(wildcard src/*/source/*.c) 

# Map src/.../*.c → obj/.../*.o
OBJS := $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCFILES))

# -------------------------------------------------
# Targets
# -------------------------------------------------
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

# Compile rule
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
