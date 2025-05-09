##
## EPITECH PROJECT, 2025
## cuddle
## File description:
## Makefile
##

TARGET := libcuddle.a

# Include
INCLUDE := -iquote./include

# Libs used
LIBS := -lm
LIBS_DIR := -L./

# Compilation Flags
CFLAGS += -Wall -Wextra $(INCLUDE)

# Flags Criterion
CRITERION += --coverage -g -lcriterion

SRC		:= $(wildcard src/**/*.c) $(wildcard src/**/**/*.c)
OBJ		:= $(patsubst src/%.c, build/%.o, $(SRC))
DIRS	:= $(sort $(dir $(OBJ)))
TEST	:= $(wildcard tests/criterion/*.c)

TEST_MAIN := ./src/main.c
SRC :=	$(filter-out $(TEST_MAIN), $(SRC))
TEST_TARGET := cuddle
TESTING_TARGET := cuddle_test

# Makefile Rules:

.PHONY: all re fclean clean test

all: $(TARGET)

# Compile source files to object files
build/%.o: src/%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories
$(DIRS):
	@mkdir -p $@

$(TARGET): $(OBJ)
	ar rc -o $(TARGET) $(OBJ) $(LIBS)

# Clean up generated objects
clean:
	rm -rf build

# Clean up generated objects and binary
fclean: clean
	rm -rf $(TARGET) $(TEST_TARGET) $(TESTING_TARGET) *.gcda *.gcno

# ReCompile all file
re: fclean all

test: CFLAGS += -g
test: SRC += $(TEST_MAIN)
test: OBJ := $(patsubst src/%.c, build/%.o, $(SRC))
test: $(OBJ)
	$(CC) $(OBJ) -o $(TEST_TARGET) $(LIBS_DIR) $(LIBS)

tests_run:	CFLAGS += $(CRITERION)
tests_run:	fclean $(TARGET)
	$(CC) $(TEST) $(OBJ) -o $(TESTING_TARGET)	\
	$(INCLUDE) $(LIBS_DIR) $(LIBS) $(CRITERION)
	./$(TESTING_TARGET)

# Test branch coverage
gcovr:	tests_run
	gcovr --exclude tests
	gcovr --exclude tests --branches
