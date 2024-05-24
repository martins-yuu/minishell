/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 03:50:29 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:32:43 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "shell/builtin.h"
#include "shell/context.h"
#include "shell/env.h"
#include "shell/path.h"
#include "utils/colors.h"
#include <stdio.h>

void	context_init(t_context *ctx)
{
	env_init(ctx);
	path_init(ctx);
	builtin_init(ctx);
}

void	context_destroy(t_context *ctx)
{
	builtin_destroy(ctx);
	path_destroy(ctx);
	env_destroy(ctx);
}

void	context_print(const t_context *ctx)
{
	t_hashmap_iterator	it;
	size_t				i;
	t_string			*val;

	ft_putendl("[" BLUE "Env" RESET "]");
	it = ft_hshbegin(ctx->env);
	while (ft_hshnext(&it))
		printf("(" MAGENTA "%s" RESET " " YELLOW "%s" RESET ")\n", it.key,
			(char *)it.value);
	ft_putendl("[" BLUE "Path" RESET "]");
	i = 0;
	while (i < ft_arrsize(ctx->path))
	{
		val = ft_arrat(ctx->path, i);
		printf("(" MAGENTA "%zu" RESET " " YELLOW "%s" RESET ")\n", i, *val);
		i++;
	}
	ft_putendl("[" BLUE "Builtins" RESET "]");
	it = ft_hshbegin(ctx->builtins);
	while (ft_hshnext(&it))
		printf("(" MAGENTA "%s" RESET ")\n", it.key);
}
