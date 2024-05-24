/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 05:32:27 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 18:40:22 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "ast/ast_types.h"

typedef enum e_ast_type			t_ast_type;
typedef struct s_ast			t_ast;

enum							e_ast_type
{
	AST_SUBSHELL,
	AST_CONDITIONAL,
	AST_PIPELINE,
	AST_COMMAND,
	AST_CMD_PREFIX,
	AST_CMD_SUFFIX,
	AST_IO_REDIRECT,
};

union							u_ast_type
{
	struct s_ast				*subshell;
	struct s_ast_conditional	conditional;
	struct s_ast_pipeline		pipeline;
	struct s_ast_command		command;
	struct s_ast_prefix			cmd_prefix;
	struct s_ast_suffix			cmd_suffix;
	struct s_ast_redirection	io_redirect;
};

struct							s_ast
{
	enum e_ast_type				type;
	union u_ast_type			as;
};

t_ast							*ast_new(t_ast ast);
void							ast_free(t_ast *ast);
void							ast_print(const t_ast *ast, int depth);

#endif
