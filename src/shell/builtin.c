/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:06:13 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 17:18:06 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hashmap.h"
#include "shell/context.h"
#include "utils/error.h"
#include <stdlib.h>

void	builtin_init(t_context *ctx)
{
	ctx->builtins = ft_hshnew(NULL);
	if (!ctx->builtins)
		error_panic("ft_hshnew");
}

void	builtin_destroy(t_context *ctx)
{
	ft_hshfree(ctx->builtins);
}
