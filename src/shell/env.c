/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:49:42 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 17:18:06 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extension/extension.h"
#include "ft_string.h"
#include "shell/context.h"
#include "shell/env.h"
#include "utils/error.h"
#include <stdlib.h>

static t_string	build_value(t_string arr[]);

void	env_init(t_context *ctx)
{
	extern char	**environ;
	size_t		i;

	ctx->env = ft_hshnew(NULL);
	if (!ctx->env)
		error_panic("ft_hshnew");
	i = 0;
	while (environ[i] != NULL)
	{
		env_set_var(ctx, environ[i]);
		i++;
	}
}

void	env_destroy(t_context *ctx)
{
	t_hashmap_iterator	it;

	it = ft_hshbegin(ctx->env);
	while (ft_hshnext(&it))
	{
		ft_stnfree((t_string)it.key);
		ft_stnfree(it.value);
	}
	ft_hshfree(ctx->env);
}

void	env_set_var(t_context *ctx, const char *str)
{
	t_string	*var;
	t_string	name;
	t_string	value;

	var = ft_split(str, '=');
	if (!var)
		error_panic("ft_split");
	name = dup_or_exit(*var);
	if (var[1])
		value = build_value(var + 1);
	else
		value = NULL;
	env_unset_var(ctx, name);
	if (!ft_hshset(ctx->env, name, value))
		error_panic("ft_hshset");
	ft_freesplit(var);
}

void	env_unset_var(t_context *ctx, const char *name)
{
	ft_hshdel2(ctx->env, name, ft_stnfree, ft_stnfree);
}

static t_string	build_value(t_string arr[])
{
	t_string	res;
	size_t		i;

	res = dup_or_exit(*arr);
	i = 1;
	while (arr[i] != NULL)
	{
		cat_or_exit(&res, "=");
		cat_or_exit(&res, arr[i]);
		i++;
	}
	return (res);
}
