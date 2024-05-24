/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:58:21 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "lexer/lexer.h"
#include "parser/parser_internal.h"
#include "token/token.h"
#include "utils/error.h"
#include <stdlib.h>
#include <unistd.h>

t_parser	*new_parser(t_lexer *lexer)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
		error_panic("malloc");
	parser->lexer = lexer;
	parser->current = NULL;
	parser->peek = NULL;
	parser->tokens = ft_arrnew(sizeof(t_token));
	if (!parser->tokens)
		error_panic("ft_arrnew");
	parser->errors = 0;
	parser_advance(parser);
	parser_advance(parser);
	return (parser);
}

void	free_parser(t_parser *parser)
{
	t_token	**tok;
	size_t	i;

	i = 0;
	while (i < ft_arrsize(parser->tokens))
	{
		tok = ft_arrat(parser->tokens, i);
		token_free(*tok);
		i++;
	}
	ft_arrfree(parser->tokens);
	free(parser);
}

t_ast	*parser_parse(t_parser *parser)
{
	if (parser_at(parser, TOKEN_NEWLINE))
		return (NULL);
	return (parser_parse_conditional(parser));
}

t_ast	*parser_parse_conditional(t_parser *parser)
{
	t_ast					*left;
	t_ast_conditional_op	op;
	t_ast					*right;

	left = parser_parse_pipeline(parser);
	if (parser_at(parser, TOKEN_AND))
		op = AST_AND_OP;
	else if (parser_at(parser, TOKEN_OR))
		op = AST_OR_OP;
	else
		return (left);
	parser_advance(parser);
	if (parser_at(parser, TOKEN_AND | TOKEN_OR | TOKEN_BAR))
		return (parser_raise_error(parser), NULL);
	right = parser_parse_conditional(parser);
	return (ast_new((t_ast){
		AST_CONDITIONAL,
		.as.conditional = {left, op, right},
	}));
}

t_ast	*parser_parse_subshell(t_parser *parser)
{
	t_ast	*subshell;

	subshell = parser_parse_conditional(parser);
	if (!parser_at(parser, TOKEN_RPAREN))
		return (parser_raise_error(parser), NULL);
	parser_advance(parser);
	if (parser_at(parser, TOKEN_LPAREN | TOKEN_RPAREN | TOKEN_WORD))
		return (parser_raise_error(parser), NULL);
	return (ast_new((t_ast){AST_SUBSHELL, .as.subshell = subshell}));
}
