/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:00:31 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 20:43:50 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "ast/ast.h"
# include "ft_arraylist.h"
# include "parser/parser.h"
# include "token/token.h"
# include <stdbool.h>
# include <stdlib.h>

struct		s_parser
{
	t_lexer	*lexer;
	t_token	*current;
	t_token	*peek;
	t_array	*tokens;
	size_t	errors;
};

bool		parser_at(t_parser *parser, t_token_type type);
void		parser_advance(t_parser *parser);
void		parser_raise_error(t_parser *parser);
t_ast		*parser_parse_subshell(t_parser *parser);
t_ast		*parser_parse_conditional(t_parser *parser);
t_ast		*parser_parse_pipeline(t_parser *parser);
t_ast		*parser_parse_command(t_parser *parser);
t_ast		*parser_parse_prefix(t_parser *parser);
t_ast		*parser_parse_suffix(t_parser *parser);
t_ast		*parser_parse_redirection(t_parser *parser);

#endif
