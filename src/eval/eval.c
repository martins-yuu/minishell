/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:17:21 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 18:54:14 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/ast.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "shell/context.h"

void	eval(t_context *ctx, const char *input)
{
	t_lexer		*lexer;
	t_parser	*parser;
	t_ast		*ast;

	(void)ctx;
	lexer = lexer_new(input);
	parser = new_parser(lexer);
	ast = parser_parse(parser);
	ast_print(ast, 0);
	ast_free(ast);
	free_parser(parser);
	lexer_free(lexer);
}
