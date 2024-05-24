/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:02:38 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 18:50:30 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "ft_string.h"
# include <stdbool.h>

typedef enum e_token_type	t_token_type;
typedef struct s_token		t_token;

enum						e_token_type
{
	TOKEN_ILLEGAL = 1 << 0,
	TOKEN_NEWLINE = 1 << 1,
	TOKEN_WORD = 1 << 2,
	TOKEN_LESS = 1 << 3,
	TOKEN_GREATER = 1 << 4,
	TOKEN_DLESS = 1 << 5,
	TOKEN_DGREATER = 1 << 6,
	TOKEN_BAR = 1 << 7,
	TOKEN_AND = 1 << 8,
	TOKEN_OR = 1 << 9,
	TOKEN_LPAREN = 1 << 10,
	TOKEN_RPAREN = 1 << 11,
};

struct						s_token
{
	enum e_token_type		type;
	t_string				literal;
};

t_token						*token_new(t_token_type type, const char *literal);
void						token_free(t_token *token);
bool						token_match(t_token *token, t_token_type type);
void						token_print(const t_token *token);

#endif
