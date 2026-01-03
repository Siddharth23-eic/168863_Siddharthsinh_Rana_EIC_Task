CC = gcc

INC_DIRS := $(shell find src -type d -name include)
CFLAGS   := -Wall -Wextra -O3 $(addprefix -I,$(INC_DIRS))
LFLAGS   =

OBJDIR  = obj
BINDIR  = bin
TARGET  = $(BINDIR)/main

SRCFILES := \
    $(wildcard src/*.c) \
    $(wildcard src/*/*.c) \
    $(wildcard src/*/*/*.c)

OBJS := $(shell \
    echo $(SRCFILES) | tr ' ' '\n' \
    | sed 's|^src/|$(OBJDIR)/|' \
    | sed 's|_src/|_obj/|g' \
    | sed 's|\.c$$|.o|' \
)

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

# 🔥 FIXED compile rule
$(OBJDIR)/%.o:
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c \
	    $(patsubst $(OBJDIR)/%.o,src/%.c,$(subst _obj,_src,$@)) \
	    -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean