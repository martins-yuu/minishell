/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:47:30 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:15:48 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include "shell/context.h"

void	path_init(t_context *ctx);
void	path_destroy(t_context *ctx);
void	path_update(t_context *ctx);

#endif
