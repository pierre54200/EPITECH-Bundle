#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "env.h"
#include "shell_command.h"
#include "token.h"
#include "ast.h"
#include "prompt.h"
#include "alias.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(shell_test, simple_command_input, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "echo Hello\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);

    // --- Verification ---
    cr_assert_stdout_eq_str("Hello\n"); // OUTPUT
}

Test(shell_test, wrong_cmd, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "oui\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, simple_ls, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, double_cmd_ls, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls;ls\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, cd, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "cd\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, cd_back, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "cd ..; cd -; pwd\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, cd_point, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "cd .; cd ..; pwd\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, and, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls && a && pwd\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, or, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls || a; ls || ls\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, pipe, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "cat | ls; ls | cat; ls |\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, command_null, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "|\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, command_null2, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls |\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, env, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "env; setenv test=test; env; unsetenv test prout; unsetenv test\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, wrong_env, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "setenv; unsetenv; env; unsetenv oui\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, setenv_wrong, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "setenv PATH ls\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, exit, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "exit\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, exit_nbr, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "exit 8\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, exit_wrong, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "exit c; exit 8 a\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
    fclose(fp);
}

Test(shell_test, find_in_env, .init = redirect_all_std)
{
    // --- Setup ---
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    find_in_env(&context, "test");
}

Test(shell_test, find_in_env_exist, .init = redirect_all_std)
{
    // --- Setup ---
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    find_in_env(&context, "PATH");
}

Test(shell_test, alias, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "alias; alias test=test; alias ls; alias ls=ls; unalias ls test; unalias\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    alias_destroy(context.aliases);
    stdin = original_stdin;
}

Test(shell_test, prompt, .init = redirect_all_std)
{
    shell_context_t context = { 0 };
    prompt_exitcode_formatter(&context);
    prompt_git_formatter(&context);
    prompt_path_formatter(&context);
    prompt_username_formatter(&context);
    prompt_time_formatter(&context);
    prompt_timer_formatter(&context);
    context.process_exitcode = 1;
    prompt_exitcode_formatter(&context);

    int env_result = env_load(&context, (char *[]){"LOGNAME=/bin", NULL});
    prompt_exitcode_formatter(&context);
    prompt_git_formatter(&context);
    prompt_path_formatter(&context);
    prompt_username_formatter(&context);
    prompt_time_formatter(&context);
    prompt_timer_formatter(&context);
    context.process_exitcode = 1;
    prompt_exitcode_formatter(&context);
}

Test(shell_test, env_var, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "$PATH\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}

Test(shell_test, parrenthesis, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls ; (ls;ls)\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}


Test(shell_test, start_parrenthesis, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls ; (ls;ls\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}

Test(shell_test, end_parrenthesis, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "ls ; ls;ls)\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}

Test(shell_test, tick, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "echo 'ls'\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}

Test(shell_test, back_tick, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "echo `ls`\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}

Test(shell_test, start_back_tick, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "echo 'ls\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}

Test(shell_test, end_back_tick, .init = redirect_all_std)
{
    // --- Setup ---
    const char *input = "echo ls'\n"; //INPUT

    // Simulate standard input using a temporary file
    FILE *fp = tmpfile();
    cr_assert_not_null(fp, "Failed to create temporary file");
    fputs(input, fp);
    rewind(fp);

    FILE *original_stdin = stdin;
    stdin = fp;

    // Initialize shell context
    shell_context_t context = { 0 };
    context.prompt_format = "[%exitcode] (%time) %user:%current_path$ ";
    int env_result = env_load(&context, (char *[]){"PATH=/bin", NULL});
    cr_assert_eq(env_result, 0, "Failed to load environment");
    // --- Execution ---
    int exit_code = shell(&context);
    (void)exit_code;

    // --- Cleanup ---
    env_free(&context);
    stdin = original_stdin;
}
