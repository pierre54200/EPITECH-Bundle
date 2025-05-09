##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

TARGET := mysh

# Include
INCLUDE := -iquote./include

# Compilation Flags
CFLAGS += -Wall -Wextra

# Flags Criterion
CRITERION += --coverage -lcriterion -g

SRC		:= $(wildcard src/*.c) $(wildcard src/**/*.c)
OBJ		:= $(patsubst src/%.c, build/%.o, $(SRC))
DIRS	:= $(sort $(dir $(OBJ)))
TEST	:= $(wildcard tests/*.c)

TESTING_TARGET := testing

# Makefile Rules:

all: $(TARGET)

# Compile source files to object files
build/%.o: src/%.c | $(DIRS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

# Create necessary directories
$(DIRS):
	@mkdir -p $@

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(INCLUDE)

# Clean up generated objects
clean:
	rm -rf build

# Clean up generated objects and binary
fclean: clean
	rm -rf $(TARGET) $(TESTING_TARGET) *.gcda *.gcno

# ReCompile all file
re: fclean all

tests_run: CFLAGS += $(CRITERION)

tests_run: OBJ := $(filter-out build/main.o, $(OBJ))

tests_run: $(OBJ)
	$(CC) $(TEST) $(OBJ) -o $(TESTING_TARGET)	\
	$(INCLUDE) $(CRITERION)
	./$(TESTING_TARGET)

debug: CFLAGS += -g
debug: all

# Test branch coverage
gcovr:	tests_run
	gcovr --exclude tests --branches

tests: fclean
	cp -r ./tests/bashtest/ .
	./tests/test.sh
	rm -r ./bashtest

.PHONY: all re fclean clean gcovr debug
