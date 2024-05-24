/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:33:52 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:54:12 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENSION_H
# define EXTENSION_H

# include "ft_string.h"

void		cat_or_exit(t_string *dst, const char *src);
t_string	dup_or_exit(const t_string s);

#endif
