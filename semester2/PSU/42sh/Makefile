##
## EPITECH PROJECT, 2025
## minishell2
## File description:
## Makefile
##

TARGET := 42sh

# Include
INCLUDE := $(shell find . -type f -name '*.h'\
					-printf '%h\n' |\
					sort -u |\
					awk '{print "-iquote",$$0}')

# Compilation Flags
CFLAGS += -Werror -Wall -Wextra	\
	-Wnull-dereference -Wduplicated-cond -Wlogical-op	\
	-Wshadow -Wfloat-equal -Wcast-align -Wunreachable-code	\
	-Wjump-misses-init -Wmissing-declarations -Wmissing-prototypes	\
	-Wundef

# Flags Criterion
CRITERION += --coverage -lgcov -g -lcriterion

SRC	= \
	src/main.c	\
	\
	src/alias/alias_adder.c	\
	src/alias/alias_destroyer.c	\
	src/alias/alias_raw_adder.c	\
	src/alias/alias_remover.c	\
	src/alias/finder/alias_parser_find.c	\
	src/alias/finder/alias_string_find.c	\
	src/alias/utils/alias_destroy_unique.c	\
	src/alias/utils/alias_reset_usage_state.c	\
	src/alias/utils/alias_is_valid_char.c	\
	src/alias/dump/alias_dumper.c	\
	src/alias/dump/alias_single_dumper.c	\
	\
	src/shell/shell.c	\
	src/shell/shell_stop.c	\
	src/shell/shell_rc_loader.c	\
	src/shell/user_input_handler.c	\
	\
	src/env/env_set_env.c	\
	src/env/env_unset_env.c	\
	src/env/env_get_env.c	\
	src/env/env_transformer.c	\
	src/env/env_free.c	\
	src/env/env_loader.c	\
	src/env/find_in_env.c	\
	\
	src/command/command_execution.c	\
	src/command/command_const.c	\
	src/command/builtin/find_builtin_command.c	\
	src/command/builtin/command_exit.c	\
	src/command/builtin/command_cd.c	\
	src/command/builtin/env/command_env.c	\
	src/command/builtin/env/command_setenv.c	\
	src/command/builtin/env/command_unsetenv.c	\
	src/command/builtin/alias/command_alias.c	\
	src/command/builtin/alias/command_unalias.c	\
	src/command/executor/command_executor.c	\
	src/command/builtin/command_color.c	\
	src/command/builtin/command_path.c	\
	src/command/builtin/jobs/command_jobs.c \
	src/command/builtin/jobs/command_bg.c \
	src/command/builtin/jobs/command_fg.c \
	src/command/builtin/jobs/manage_jobs.c \
	src/command/builtin/jobs/update_jobs.c \
	\
	src/ast/parser/parser.c	\
	src/ast/parser/parser_free.c	\
	src/ast/parser/utils/parser_dumper.c	\
	src/ast/parser/utils/parser_finder_token_creator.c	\
	src/ast/parser/utils/parser_add_new_token.c	\
	src/ast/parser/utils/parser_add_token.c	\
	src/ast/parser/utils/parser_tokens_match.c	\
	src/ast/parser/utils/parser_tokens_perfect_match.c	\
	src/ast/parser/utils/parser_skip_tokens.c	\
	src/ast/parser/parser_const.c	\
		src/ast/parser/builder/parser_builder_escape.c	\
		src/ast/parser/builder/parser_builder_raw.c	\
		src/ast/parser/builder/parser_builder_quote.c	\
		src/ast/parser/builder/parser_builder_backtick.c	\
	\
	src/globbing/globbing_loader.c	\
	src/globbing/globbing_dir_loader.c	\
	src/globbing/globbing_finder.c	\
	src/globbing/utils/globbing_isolate_globbing.c	\
	src/globbing/utils/globbing_should_deep_search.c	\
	src/globbing/utils/globbing_build_path.c	\
	src/globbing/utils/globbing_skip_dir.c	\
	src/globbing/matcher/globbing_matcher.c	\
	src/globbing/matcher/globbing_matcher_const.c	\
	src/globbing/matcher/globbing_matcher_finder.c	\
	src/globbing/matcher/matcher/globbing_matcher_any_wildcard.c	\
	src/globbing/matcher/matcher/globbing_matcher_single_wildcard.c	\
	src/globbing/matcher/matcher/globbing_matcher_choices.c	\
	src/globbing/matcher/matcher/globbing_matcher_char.c	\
	\
	src/ast/ast_builder.c	\
	src/ast/ast_executor.c	\
	src/ast/ast_validator.c	\
	src/ast/ast_free.c	\
	src/ast/utils/ast_find_stage.c	\
	src/ast/utils/ast_dumper.c	\
	src/ast/ast_const.c	\
		\
		src/ast/builder/literal/build_literal_node.c	\
		src/ast/builder/io/build_io_node.c	\
		src/ast/builder/linker/build_linker_node.c	\
		src/ast/builder/separator/build_separator_node.c	\
		src/ast/builder/parenthese/build_parenthese_node.c	\
		\
		src/ast/resolver/io/ast_write_resolver.c	\
		src/ast/resolver/io/ast_append_resolver.c	\
		src/ast/resolver/io/ast_send_file_resolver.c	\
		src/ast/resolver/io/ast_send_stdin_resolver.c	\
		src/ast/resolver/linker/ast_and_resolver.c	\
		src/ast/resolver/linker/ast_or_resolver.c	\
		src/ast/resolver/linker/ast_pipe_resolver.c	\
		src/ast/resolver/literal/ast_literal_resolver.c	\
		src/ast/resolver/separator/ast_fork_resolver.c	\
		src/ast/resolver/separator/ast_separator_resolver.c	\
		src/ast/resolver/parenthese/ast_parenthese_resolver.c	\
		\
		src/ast/executor/io/ast_write_executor.c	\
		src/ast/executor/io/ast_append_executor.c	\
		src/ast/executor/io/ast_send_file_executor.c	\
		src/ast/executor/io/ast_send_stdin_executor.c	\
		src/ast/executor/linker/ast_and_executor.c	\
		src/ast/executor/linker/ast_or_executor.c	\
		src/ast/executor/linker/ast_pipe_executor.c	\
		src/ast/executor/literal/ast_literal_executor.c	\
		src/ast/executor/separator/ast_fork_executor.c	\
		src/ast/executor/separator/ast_separator_executor.c	\
		src/ast/executor/parenthese/ast_parenthese_executor.c	\
		\
		src/ast/validator/io/ast_write_validator.c	\
		src/ast/validator/io/ast_append_validator.c	\
		src/ast/validator/io/ast_send_file_validator.c	\
		src/ast/validator/io/ast_send_stdin_validator.c	\
		src/ast/validator/linker/ast_and_validator.c	\
		src/ast/validator/linker/ast_or_validator.c	\
		src/ast/validator/linker/ast_pipe_validator.c	\
		src/ast/validator/literal/ast_literal_validator.c	\
		src/ast/validator/separator/ast_fork_validator.c	\
		src/ast/validator/separator/ast_separator_validator.c	\
		src/ast/validator/parenthese/ast_parenthese_validator.c	\
	\
	src/ast/token/token_const.c	\
	src/ast/token/token_dumper.c	\
	src/ast/token/token_free.c	\
	src/ast/token/tokenizer.c	\
		\
		src/ast/token/finder/literal/literal_finder.c	\
		src/ast/token/finder/literal/alias_finder.c	\
		src/ast/token/finder/literal/variable_finder.c	\
		src/ast/token/finder/io/write_finder.c	\
		src/ast/token/finder/io/append_finder.c	\
		src/ast/token/finder/io/send_file_finder.c	\
		src/ast/token/finder/io/send_stdin_finder.c	\
		src/ast/token/finder/linker/or_finder.c	\
		src/ast/token/finder/linker/and_finder.c	\
		src/ast/token/finder/linker/pipe_finder.c	\
		src/ast/token/finder/separator/semicolon_finder.c	\
		src/ast/token/finder/separator/fork_finder.c	\
		src/ast/token/finder/parenthese/parenthese_finder.c 	\
	\
	src/string/my_add_to_array.c	\
	src/string/my_free_str_array.c	\
	src/string/my_remove_trailing_char.c \
	src/string/my_array_to_str.c \
	\
	src/prompt/prompt_ask_user.c	\
	src/prompt/prompt_get_input.c	\
	src/prompt/formatter/prompt_formatter.c	\
	src/prompt/formatter/prompt_formatter_const.c	\
	src/prompt/formatter/format/prompt_path_formatter.c	\
	src/prompt/formatter/format/prompt_exitcode_formatter.c	\
	src/prompt/formatter/format/prompt_time_formatter.c	\
	src/prompt/formatter/format/prompt_timer_formatter.c	\
	src/prompt/formatter/format/prompt_git_formatter.c	\
	src/prompt/formatter/format/prompt_username_formatter.c

SRC :=	$(filter-out $(TEST_MAIN), $(SRC))
OBJ		:= $(patsubst src/%.c, build/obj/%.o, $(SRC))
DIRS	:= $(sort $(dir $(OBJ)))

TEST_SRC	:= $(shell find ./tests/ -type f -name '*.c')
TEST_OBJ	:= $(patsubst src/%.c, build/obj/%.o, $(SRC))
TEST_OBJ	+= $(patsubst tests/%.c, build/obj/tests/%.o, $(TEST_SRC))

TEST_TARGET := 42sh
TESTING_TARGET := 42sh_test

BUILT_OBJ =

# Makefile Rules:

all: $(TARGET)
	@printf "\e[38;5;029m✅ Everything is up to date !\e[0m\n"

# Compile source files to object files
build/obj/%.o: src/%.c | $(DIRS)
	@printf "\
	\e[38;5;008m[-Werror -Wall -Wextra ... -iquote ...]\e[0m \
	\e[38;5;117m$(notdir $<)\e[0m\
	\e[38;5;183m -> \e[0m\
	\e[38;5;220m$@\e[0m\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(eval BUILT_OBJ += $@)

# Create necessary directories
$(DIRS):
	@mkdir -p $@

$(TARGET): $(OBJ)
	@printf "\e[38;5;029m✅ Successfully compiled target object !\e[0m\n"
	@printf "\e[38;5;029m🔄 Compiling target !\e[0m\n"
	@printf "\e[38;5;029m📜 Name: \e[38;5;220m$(TARGET)\e[0m\n"
	@printf "\e[38;5;029m✅ Successfully compiled target !\e[0m\n"
	@mkdir -p build/bin/
	@gcc -o build/bin/$(TARGET) $(OBJ)
	@cp build/bin/$(TARGET) .

# Clean up generated objects
clean:
	@printf "\e[38;5;124m🔥 Remove build/obj directory !\e[0m\n"
	@rm -rf build/obj

# Clean up generated objects and binary
fclean:
	@printf "\e[38;5;124m🔥 Remove build directory !\e[0m\n"
	@rm -rf build
	@printf "\e[38;5;124m🔥 Remove binary and criterion file !\e[0m\n"
	@rm -rf $(TARGET) $(TEST_TARGET) $(TESTING_TARGET) *.gcda *.gcno

# ReCompile all file
re: fclean all

debug_message:
	@printf "\e[38;5;220m🔥 Debug mode !\e[0m\n"

debug: debug_message
debug: CFLAGS += -g
debug: all

redebug: debug_message
redebug: CFLAGS += -g
redebug: re

tests_run: CFLAGS += $(CRITERION)
tests_run: TEST_OBJ := $(filter-out build/obj/main.o, $(TEST_OBJ))
tests_run: fclean $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o build/$(TESTING_TARGET) $(INCLUDE) $(CRITERION)
	./build/$(TESTING_TARGET)

gcovr_branches:	tests_run
	gcovr --exclude tests --txt-metric branch

gcovr_classic:	tests_run
	gcovr --exclude tests

.PHONY: all re fclean clean debug redebug gcovr tests_run
