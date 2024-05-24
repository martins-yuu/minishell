/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:58:07 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"
#include "lexer/lexer_internal.h"
#include "utils/colors.h"
#include "utils/error.h"
#include <stdlib.h>

t_lexer	*lexer_new(const char *input)
{
	t_lexer	*lexer;

	if (!input)
	{
		ft_putendl_fd(RED "lexer_new" RESET ": " RESET "input is NULL",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	lexer = malloc(sizeof(t_lexer));
	if (!lexer)
		error_panic("malloc");
	lexer->input = ft_stnnew(input);
	if (!lexer->input)
		error_panic("ft_stnnew");
	lexer->current_position = 0;
	lexer->read_position = 0;
	lexer_advance(lexer);
	return (lexer);
}

void	lexer_free(t_lexer *lexer)
{
	ft_stnfree(lexer->input);
	free(lexer);
}

t_token	*lexer_next_token(t_lexer *lexer)
{
	t_token		*tok;
	t_string	literal;

	lexer_skip_whitespace(lexer);
	if (lexer_at_end(lexer))
		return (token_new(TOKEN_NEWLINE, "<newline>"));
	if (lexer_is_meta(lexer->c))
	{
		tok = lexer_try_produce_operator(lexer);
		lexer_advance(lexer);
		return (tok);
	}
	literal = lexer_scan_word(lexer);
	tok = token_new(TOKEN_WORD, literal);
	ft_stnfree(literal);
	return (tok);
}
