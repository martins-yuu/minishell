/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 03:11:35 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 19:44:39 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"
#include "token/token.h"
#include "utils/colors.h"
#include "utils/error.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

t_token	*token_new(t_token_type type, const char *literal)
{
	t_token	*tok;

	if (!literal)
	{
		ft_putendl_fd(RED "token_new" RESET ": " RESET "literal is NULL",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	tok = malloc(sizeof(t_token));
	if (!tok)
		error_panic("malloc");
	tok->type = type;
	tok->literal = ft_stnnew(literal);
	if (!tok->literal)
		error_panic("ft_stnnew");
	return (tok);
}

void	token_free(t_token *token)
{
	ft_stnfree(token->literal);
	free(token);
}

bool	token_match(t_token *token, t_token_type type)
{
	return (token->type & type);
}

void	token_print(const t_token *token)
{
	printf("(t_token){type: %04d, literal: %s}\n", token->type, token->literal);
}
