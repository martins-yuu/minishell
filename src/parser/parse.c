/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:54:44 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "lexer/lexer_internal.h"
#include "parser/parser_internal.h"
#include "token/token.h"
#include "utils/colors.h"
#include "utils/error.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	parser_at(t_parser *parser, t_token_type type)
{
	if (parser->current == NULL)
		return (false);
	return (token_match(parser->current, type));
}

void	parser_advance(t_parser *parser)
{
	parser->current = parser->peek;
	if (parser_at(parser, TOKEN_ILLEGAL))
		parser_raise_error(parser);
	parser->peek = lexer_next_token(parser->lexer);
	if (!ft_arrappend(parser->tokens, &parser->peek))
		error_panic("ft_arrappend");
	if (parser->current != NULL)
		token_print(parser->current);
}

void	parser_raise_error(t_parser *parser)
{
	if (parser->errors > 0)
		return ;
	ft_putstr_fd(RED "rmsh" RESET ": " RESET "syntax error near ",
		STDERR_FILENO);
	ft_putstr_fd(YELLOW "'", STDERR_FILENO);
	ft_putstr_fd(parser->current->literal, STDERR_FILENO);
	ft_putstr_fd("'" RESET "\n", STDERR_FILENO);
	parser->errors++;
}
