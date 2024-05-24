/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:49:32 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:16:00 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "shell/context.h"

void	env_init(t_context *ctx);
void	env_destroy(t_context *ctx);
void	env_set_var(t_context *ctx, const char *str);
void	env_unset_var(t_context *ctx, const char *name);

#endif
