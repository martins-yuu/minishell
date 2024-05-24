/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 03:09:51 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "lexer/lexer_internal.h"
#include "utils/error.h"
#include <stdbool.h>
#include <stdlib.h>

static void	lexer_handle_unclosed_quote(t_string *str, char quote);

t_string	lexer_scan_word(t_lexer *lexer)
{
	t_string	str;
	size_t		from;
	char		quote;

	from = lexer->current_position;
	quote = '\0';
	while (true)
	{
		if (lexer_is_quoting(lexer->c))
		{
			if (!quote)
				quote = lexer->c;
			else if (lexer_is_at(lexer, quote))
				quote = 0;
		}
		if (lexer_at_end(lexer) || (!quote && lexer_is_meta(lexer->c)))
			break ;
		lexer_advance(lexer);
	}
	str = ft_stnnew_size(lexer->input + from, lexer->current_position - from);
	if (!str)
		error_panic("ft_stnnew_size");
	lexer_handle_unclosed_quote(&str, quote);
	return (str);
}

static void	lexer_handle_unclosed_quote(t_string *str, char quote)
{
	if (!quote)
		return ;
	*str = ft_stncat_size(*str, &quote, sizeof(quote));
	if (!*str)
		error_panic("ft_stncat_size");
}
