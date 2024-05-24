/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 23:34:22 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 18:41:59 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_TYPES_H
# define AST_TYPES_H

# include "ft_string.h"

typedef enum e_ast_conditional_op	t_ast_conditional_op;
typedef struct s_ast_conditional	t_ast_conditional;
typedef struct s_ast_pipeline		t_ast_pipeline;
typedef struct s_ast_command		t_ast_command;
typedef struct s_ast_prefix			t_ast_prefix;
typedef struct s_ast_suffix			t_ast_suffix;
typedef enum e_ast_redirection_op	t_ast_redirection_op;
typedef struct s_ast_redirection	t_ast_redirection;

enum								e_ast_conditional_op
{
	AST_AND_OP,
	AST_OR_OP,
};

struct								s_ast_conditional
{
	struct s_ast					*left;
	enum e_ast_conditional_op		op;
	struct s_ast					*right;
};

struct								s_ast_pipeline
{
	struct s_ast					*left;
	struct s_ast					*right;
};

struct								s_ast_command
{
	struct s_ast					*prefix;
	t_string						cmd_name;
	struct s_ast					*suffix;
};

struct								s_ast_prefix
{
	struct s_ast					*prefix;
	struct s_ast					*redirection;
};

struct								s_ast_suffix
{
	struct s_ast					*suffix;
	t_string						word;
	struct s_ast					*redirection;
};

enum								e_ast_redirection_op
{
	AST_LESS_OP,
	AST_GREATER_OP,
	AST_DLESS_OP,
	AST_DGREATER_OP,
};

struct								s_ast_redirection
{
	enum e_ast_redirection_op		op;
	t_string						filename;
};

#endif
