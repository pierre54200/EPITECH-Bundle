/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** ast_executor
*/

#include "ast.h"

static ast_executor_t find_executor(ast_t *ast)
{
    for (size_t i = 0; i < ast_executor_count; i++) {
        if (!ast_executor[i].resolver(ast)) {
            continue;
        }
        return ast_executor[i];
    }
    return (ast_executor_t){ 0 };
}

exitcode_t ast_exec(ast_t *ast)
{
    ast_executor_t executor = find_executor(ast);

    if (executor.execute == NULL || executor.resolver == NULL) {
        return 0;
    }
    return executor.execute(ast);
}
