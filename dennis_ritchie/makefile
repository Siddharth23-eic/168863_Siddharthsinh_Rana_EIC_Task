CC := gcc

OBJDIR := obj
BINDIR := bin
TARGET := $(BINDIR)/main

# -------------------------------------------------
# Include paths
# -------------------------------------------------
INC_DIRS := include $(shell find src -type d -name include)
CFLAGS := -Wall -Wextra -O3 $(addprefix -I,$(INC_DIRS))
LDFLAGS := -lm

# -------------------------------------------------
# Collect all sources
# -------------------------------------------------
SRCFILES := $(shell find src -name '*.c')

# -------------------------------------------------
# Object mapping (ORDER IS CRITICAL)
# -------------------------------------------------
OBJS := $(SRCFILES)
OBJS := $(OBJS:/src/=/obj/)
OBJS := $(OBJS:src/%=$(OBJDIR)/%)
OBJS := $(OBJS:.c=.o)

# -------------------------------------------------
# Build
# -------------------------------------------------
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# -------------------------------------------------
# Compile rule (exact reverse mapping)
# -------------------------------------------------
$(OBJDIR)/%.o:
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c \
	  $(patsubst $(OBJDIR)/%.o,src/%.c,$(subst /obj/,/src/,$@)) \
	  -o $@

# -------------------------------------------------
# Clean
# -------------------------------------------------
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean