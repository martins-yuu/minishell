/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_internal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 00:14:20 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 19:00:12 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_INTERNAL_H
# define LEXER_INTERNAL_H

# include "ft_string.h"
# include "lexer/lexer.h"
# include <stdbool.h>
# include <stdlib.h>

struct			s_lexer
{
	t_string	input;
	size_t		current_position;
	size_t		read_position;
	char		c;
};

void			lexer_advance(t_lexer *lexer);
bool			lexer_match(t_lexer *lexer, char expected);
void			lexer_skip_whitespace(t_lexer *lexer);
t_token			*lexer_try_produce_operator(t_lexer *lexer);
t_string		lexer_scan_word(t_lexer *lexer);
bool			lexer_is_at(const t_lexer *lexer, char c);
bool			lexer_at_end(const t_lexer *lexer);
bool			lexer_is_meta(char c);
bool			lexer_is_quoting(char c);

#endif
