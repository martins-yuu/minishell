/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:09:31 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/11 20:18:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "lexer/lexer_internal.h"
#include <stdbool.h>

#define META " \t\n|&()<>"
#define QUOTING "'\""

bool	lexer_is_at(const t_lexer *lexer, char c)
{
	return (lexer->c == c);
}

bool	lexer_at_end(const t_lexer *lexer)
{
	return (lexer->c == '\0');
}

bool	lexer_is_meta(char c)
{
	return (ft_strchr(META, c) != NULL);
}

bool	lexer_is_quoting(char c)
{
	return (ft_strchr(QUOTING, c) != NULL);
}
