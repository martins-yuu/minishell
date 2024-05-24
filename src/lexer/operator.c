/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:21:08 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/lexer_internal.h"
#include "token/token.h"
#include <stdlib.h>

t_token	*lexer_try_produce_operator(t_lexer *lexer)
{
	if (lexer_is_at(lexer, '<') && lexer_match(lexer, '<'))
		return (token_new(TOKEN_DLESS, "<<"));
	else if (lexer_is_at(lexer, '<'))
		return (token_new(TOKEN_LESS, "<"));
	else if (lexer_is_at(lexer, '>') && lexer_match(lexer, '>'))
		return (token_new(TOKEN_DGREATER, ">>"));
	else if (lexer_is_at(lexer, '>'))
		return (token_new(TOKEN_GREATER, ">"));
	else if (lexer_is_at(lexer, '|') && lexer_match(lexer, '|'))
		return (token_new(TOKEN_OR, "||"));
	else if (lexer_is_at(lexer, '|'))
		return (token_new(TOKEN_BAR, "|"));
	else if (lexer_is_at(lexer, '&') && lexer_match(lexer, '&'))
		return (token_new(TOKEN_AND, "&&"));
	else if (lexer_is_at(lexer, '&'))
		return (token_new(TOKEN_ILLEGAL, "&"));
	else if (lexer_is_at(lexer, '('))
		return (token_new(TOKEN_LPAREN, "("));
	else if (lexer_is_at(lexer, ')'))
		return (token_new(TOKEN_RPAREN, ")"));
	return (NULL);
}
