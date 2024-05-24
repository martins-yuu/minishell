/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:04:00 by yuuko             #+#    #+#             */
/*   Updated: 2024/06/05 16:32:43 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "shell/context.h"
#include "shell/repl.h"
#include "utils/colors.h"
#include <stdlib.h>

int	main(void)
{
	t_context	ctx;

	context_init(&ctx);
	ft_putendl("Welcome to " CYAN "rmsh" RESET);
	ft_putendl("Abandon all hope, ye who enter here.");
	repl_start(&ctx);
	ft_putendl(MAGENTA "Thence we came forth to rebehold the stars." RESET);
	context_destroy(&ctx);
	return (EXIT_SUCCESS);
}
