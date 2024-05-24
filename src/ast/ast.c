/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:32:38 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 20:46:34 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/ast.h"
#include "utils/colors.h"
#include "utils/error.h"
#include <stdlib.h>

t_ast	*ast_new(t_ast ast)
{
	t_ast	*new;

	new = malloc(sizeof(t_ast));
	if (!new)
		error_panic("malloc");
	*new = ast;
	return (new);
}

void	ast_free(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == AST_SUBSHELL)
		ast_free(ast->as.subshell);
	else if (ast->type == AST_CONDITIONAL)
		(ast_free(ast->as.conditional.left),
			ast_free(ast->as.conditional.right));
	else if (ast->type == AST_PIPELINE)
		(ast_free(ast->as.pipeline.left), ast_free(ast->as.pipeline.right));
	else if (ast->type == AST_COMMAND)
		(ast_free(ast->as.command.prefix), ast_free(ast->as.command.suffix));
	else if (ast->type == AST_CMD_PREFIX)
		(ast_free(ast->as.cmd_prefix.prefix),
			ast_free(ast->as.cmd_prefix.redirection));
	else if (ast->type == AST_CMD_SUFFIX)
		(ast_free(ast->as.cmd_suffix.suffix),
			ast_free(ast->as.cmd_suffix.redirection));
	free(ast);
}

void	ast_print(const t_ast *ast, int depth)
{
#include <stdio.h>
#define INDENT_SIZE 4
	if (!ast)
		return ;
	switch (ast->type)
	{
	case AST_SUBSHELL:
		printf("%*s" GREEN "SUBSHELL" RESET "\n", depth * INDENT_SIZE, "");
		ast_print(ast->as.subshell, depth + 1);
		printf("%*s" RED "END_SUBSHELL" RESET "\n", depth * INDENT_SIZE, "");
		break ;
	case AST_CONDITIONAL:
		printf("%*s" GREEN "CONDITIONAL" RESET "\n", depth * INDENT_SIZE, "");
		ast_print(ast->as.conditional.left, depth + 1);
		printf("%*s" YELLOW "op: " RESET "%s\n", depth * INDENT_SIZE, "",
			ast->as.conditional.op == AST_AND_OP ? "&&" : "||");
		ast_print(ast->as.conditional.right, depth + 1);
		printf("%*s" RED "END_CONDITIONAL" RESET "\n", depth * INDENT_SIZE, "");
		break ;
	case AST_PIPELINE:
		printf("%*s" GREEN "PIPELINE" RESET "\n", depth * INDENT_SIZE, "");
		ast_print(ast->as.pipeline.left, depth + 1);
		ast_print(ast->as.pipeline.right, depth + 1);
		printf("%*s" RED "END_PIPELINE" RESET "\n", depth * INDENT_SIZE, "");
		break ;
	case AST_COMMAND:
		printf("%*s" GREEN "COMMAND" RESET "\n", depth * INDENT_SIZE, "");
		ast_print(ast->as.command.prefix, depth + 1);
		printf("%*s" YELLOW "cmd_name: " RESET "%s\n", depth * INDENT_SIZE, "",
			ast->as.command.cmd_name);
		ast_print(ast->as.command.suffix, depth + 1);
		printf("%*s" RED "END_COMMAND" RESET "\n", depth * INDENT_SIZE, "");
		break ;
	case AST_CMD_PREFIX:
		printf("%*s" GREEN "CMD_PREFIX" RESET "\n", depth * INDENT_SIZE, "");
		ast_print(ast->as.cmd_prefix.prefix, depth + 1);
		ast_print(ast->as.cmd_prefix.redirection, depth + 1);
		printf("%*s" RED "END_CMD_PREFIX" RESET "\n", depth * INDENT_SIZE, "");
		break ;
	case AST_CMD_SUFFIX:
		printf("%*s" GREEN "CMD_SUFFIX" RESET "\n", depth * INDENT_SIZE, "");
		ast_print(ast->as.cmd_suffix.suffix, depth + 1);
		printf("%*s" YELLOW "word: " RESET "%s\n", depth * INDENT_SIZE, "",
			ast->as.cmd_suffix.word);
		ast_print(ast->as.cmd_suffix.redirection, depth + 1);
		printf("%*s" RED "END_CMD_SUFFIX" RESET "\n", depth * INDENT_SIZE, "");
		break ;
	case AST_IO_REDIRECT:
		printf("%*s" GREEN "IO_REDIRECT" RESET "\n", depth * INDENT_SIZE, "");
		printf("%*s" YELLOW "op: " RESET " ", depth * INDENT_SIZE, "");
		switch (ast->as.io_redirect.op)
		{
		case AST_LESS_OP:
			printf("<\n");
			break ;
		case AST_GREATER_OP:
			printf(">\n");
			break ;
		case AST_DLESS_OP:
			printf("<<\n");
			break ;
		case AST_DGREATER_OP:
			printf(">>\n");
			break ;
		}
		printf("%*s" YELLOW "filename: " RESET "%s\n", depth * INDENT_SIZE, "",
			ast->as.io_redirect.filename);
	}
}
