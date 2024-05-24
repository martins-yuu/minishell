/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:28:00 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:32:43 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval/eval.h"
#include "ft_string.h"
#include "shell/context.h"
#include "stdio.h"
#include "utils/colors.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdlib.h>

#define PROMPT "> "
#define DEBUG_STR "#!info"

void	repl_start(t_context *ctx)
{
	char	*line;

	while (true)
	{
		printf("%s " BLUE "%s" RESET " (%d)\n", getenv("USER"), getenv("PWD"),
			0);
		line = readline(GREEN PROMPT RESET);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		if (ft_strncmp(line, DEBUG_STR, sizeof(DEBUG_STR)) == 0)
			context_print(ctx);
		else
			eval(ctx, line);
		free(line);
	}
	rl_clear_history();
}
