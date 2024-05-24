/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 03:57:41 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:13:57 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "ft_arraylist.h"
# include "ft_hashmap.h"

typedef struct s_context
{
	t_hashmap	*env;
	t_array		*path;
	t_hashmap	*builtins;
}				t_context;

void			context_init(t_context *ctx);
void			context_destroy(t_context *ctx);
void			context_print(const t_context *ctx);

#endif
