/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 06:37:19 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/ast.h"
#include "parser/parser_internal.h"
#include "token/token.h"
#include <stdbool.h>
#include <stdlib.h>

t_ast	*parser_parse_pipeline(t_parser *parser)
{
	t_ast	*left;
	t_ast	*right;

	left = parser_parse_command(parser);
	if (!parser_at(parser, TOKEN_BAR))
		return (left);
	parser_advance(parser);
	if (parser_at(parser, TOKEN_AND | TOKEN_OR | TOKEN_BAR))
		return (parser_raise_error(parser), NULL);
	right = parser_parse_pipeline(parser);
	return (ast_new((t_ast){
		AST_PIPELINE,
		.as.pipeline = {left, right},
	}));
}

t_ast	*parser_parse_command(t_parser *parser)
{
	t_ast		*prefix;
	t_string	cmd_name;
	t_ast		*suffix;

	if (parser_at(parser, TOKEN_LPAREN))
	{
		parser_advance(parser);
		return (parser_parse_subshell(parser));
	}
	prefix = parser_parse_prefix(parser);
	cmd_name = parser->current->literal;
	parser_advance(parser);
	suffix = parser_parse_suffix(parser);
	return (ast_new((t_ast){
		AST_COMMAND,
		.as.command = {prefix, cmd_name, suffix},
	}));
}

t_ast	*parser_parse_prefix(t_parser *parser)
{
	t_ast	*prefix;
	t_ast	*redirection;

	prefix = NULL;
	redirection = parser_parse_redirection(parser);
	if (redirection)
		prefix = parser_parse_prefix(parser);
	return (ast_new((t_ast){
		AST_CMD_PREFIX,
		.as.cmd_prefix = {prefix, redirection},
	}));
}

t_ast	*parser_parse_suffix(t_parser *parser)
{
	t_ast		*suffix;
	t_string	word;
	t_ast		*redirection;

	suffix = NULL;
	word = NULL;
	redirection = parser_parse_redirection(parser);
	if (redirection)
		suffix = parser_parse_suffix(parser);
	else if (parser_at(parser, TOKEN_WORD))
	{
		word = parser->current->literal;
		parser_advance(parser);
		suffix = parser_parse_suffix(parser);
	}
	return (ast_new((t_ast){
		AST_CMD_SUFFIX,
		.as.cmd_suffix = {suffix, word, redirection},
	}));
}

t_ast	*parser_parse_redirection(t_parser *parser)
{
	t_ast_redirection_op	op;
	t_string				filename;

	if (parser_at(parser, TOKEN_LESS))
		op = AST_LESS_OP;
	else if (parser_at(parser, TOKEN_GREATER))
		op = AST_GREATER_OP;
	else if (parser_at(parser, TOKEN_DLESS))
		op = AST_DLESS_OP;
	else if (parser_at(parser, TOKEN_DGREATER))
		op = AST_DGREATER_OP;
	else
		return (NULL);
	parser_advance(parser);
	if (!parser_at(parser, TOKEN_WORD))
		return (parser_raise_error(parser), NULL);
	filename = parser->current->literal;
	parser_advance(parser);
	return (ast_new((t_ast){
		AST_IO_REDIRECT,
		.as.io_redirect = {op, filename},
	}));
}
