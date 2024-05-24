/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:52:59 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 18:59:39 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "token/token.h"

typedef struct s_lexer	t_lexer;

t_lexer					*lexer_new(const char *input);
void					lexer_free(t_lexer *lexer);
t_token					*lexer_next_token(t_lexer *lexer);

#endif
