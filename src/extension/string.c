/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:34:25 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 17:18:06 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "utils/error.h"

void	cat_or_exit(t_string *dst, const char *src)
{
	*dst = ft_stncat(*dst, src);
	if (!*dst)
		error_panic("ft_stncat");
}

t_string	dup_or_exit(const t_string s)
{
	t_string	ret;

	ret = ft_stndup(s);
	if (!ret)
		error_panic("ft_stndup");
	return (ret);
}
