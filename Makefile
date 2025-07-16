# Social Media Platform Makefile
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = social_media
SRCDIR = code
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/comment.c $(SRCDIR)/platform.c $(SRCDIR)/post.c $(SRCDIR)/reply.c
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Run with test input
test: $(TARGET)
	./$(TARGET) < tests/test_input.txt

# Run comprehensive tests
test-all: $(TARGET)
	@echo "Running basic tests..."
	./$(TARGET) < tests/test_input.txt
	@echo "Running edge case tests..."
	./$(TARGET) < tests/test_edge_clean.txt
	@echo "Running stress tests..."
	./$(TARGET) < tests/test_stress.txt
	@echo "Running memory tests..."
	./$(TARGET) < tests/test_memory.txt
	@echo "Running validation tests..."
	./$(TARGET) < tests/test_final_validation.txt

# Run test suite with summary
test-suite: $(TARGET)
	@if command -v bash >/dev/null 2>&1; then \
		chmod +x run_tests.sh && ./run_tests.sh; \
	else \
		echo "Running tests manually..."; \
		$(MAKE) test-all; \
	fi

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET).exe

# Debug build
debug: CFLAGS += -DDEBUG -O0
debug: $(TARGET)

# Release build
release: CFLAGS += -O2 -DNDEBUG
release: $(TARGET)

# Memory check (if valgrind is available)
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) < tests/test_input.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all         - Build the program (default)"
	@echo "  run         - Build and run the program"
	@echo "  test        - Run basic tests"
	@echo "  test-all    - Run comprehensive test suite"
	@echo "  test-suite  - Run test suite with summary"
	@echo "  clean       - Remove build files"
	@echo "  debug       - Build with debug flags"
	@echo "  release     - Build optimized release version"
	@echo "  memcheck    - Run with memory leak detection"
	@echo "  help        - Show this help message"

.PHONY: all run test test-all test-suite clean debug release memcheck help
