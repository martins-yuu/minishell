/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:46:04 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 17:18:06 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extension/extension.h"
#include "ft_arraylist.h"
#include "ft_hashmap.h"
#include "ft_string.h"
#include "shell/context.h"
#include "shell/path.h"
#include "utils/error.h"
#include <stdlib.h>

static void	clear_path(t_context *ctx);

void	path_init(t_context *ctx)
{
	ctx->path = ft_arrnew(sizeof(t_string));
	if (!ctx->path)
		error_panic("ft_arrnew");
	path_update(ctx);
}

void	path_destroy(t_context *ctx)
{
	clear_path(ctx);
	ft_arrfree(ctx->path);
}

void	path_update(t_context *ctx)
{
	t_string	pathnames;
	t_string	*values;
	size_t		i;
	t_string	val;

	clear_path(ctx);
	pathnames = ft_hshget(ctx->env, "PATH");
	if (!pathnames)
		return ;
	values = ft_split(pathnames, ':');
	if (!values)
		error_panic("ft_split");
	i = 0;
	while (values[i] != NULL)
	{
		val = dup_or_exit(values[i]);
		if (!ft_arrappend(ctx->path, &val))
			error_panic("ft_arrappend");
		i++;
	}
	ft_freesplit(values);
	return ;
}

static void	clear_path(t_context *ctx)
{
	size_t		i;
	t_string	*val;

	i = 0;
	while (i < ft_arrsize(ctx->path))
	{
		val = ft_arrat(ctx->path, i);
		ft_stnfree(*val);
		i++;
	}
	ft_arrclear(ctx->path);
}
