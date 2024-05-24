/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:52:38 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 19:29:32 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "ast/ast.h"
# include "lexer/lexer.h"

typedef struct s_parser	t_parser;

t_parser				*new_parser(t_lexer *lexer);
void					free_parser(t_parser *parser);
t_ast					*parser_parse(t_parser *parser);

#endif
