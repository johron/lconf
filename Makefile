# Define the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Ihdr

# Define the target executable
TARGET = main

# Define the source files
SRCS = src/main.c src/util.c src/lexer.c

# Define the object files directory
OBJDIR = out

# Define the object files
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source files into object files
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the object files directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

run: $(TARGET)
	$(MAKE) all
	./$(TARGET)

# Clean up the build files
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(OBJDIR)

.PHONY: all clean