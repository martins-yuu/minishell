/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:20:44 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"
#include "lexer/lexer_internal.h"
#include <stdbool.h>

static char	lexer_peek(const t_lexer *lexer);

void	lexer_advance(t_lexer *lexer)
{
	lexer->c = lexer_peek(lexer);
	lexer->current_position = lexer->read_position;
	lexer->read_position++;
}

bool	lexer_match(t_lexer *lexer, char expected)
{
	if (lexer_at_end(lexer))
		return (false);
	if (lexer_peek(lexer) == expected)
	{
		lexer_advance(lexer);
		return (true);
	}
	return (false);
}

void	lexer_skip_whitespace(t_lexer *lexer)
{
	while (ft_isspace(lexer->c))
		lexer_advance(lexer);
}

static char	lexer_peek(const t_lexer *lexer)
{
	if (lexer->read_position >= ft_stnlen(lexer->input))
		return ('\0');
	return (lexer->input[lexer->read_position]);
}
