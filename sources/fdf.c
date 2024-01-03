/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:54 by gbrunet           #+#    #+#             */
/*   Updated: 2024/01/03 10:13:50 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

void	free_lines(t_env *e)
{
	int	y;

	free(e->map.name);
	y = 0;
	while (y < e->map.y_max)
	{
		free(e->map.lines[y]);
		y++;
	}
	free(e->map.lines);
}

int	get_map(t_env *e)
{
	if (!check_file(e))
	{
		free(e->map.name);
		return (0);
	}
	if (!get_lines(e))
	{
		free(e->map.name);
		return (0);
	}
	if (!decode_lines(e))
	{
		free_lines(e);
		return (0);
	}
	free_lines(e);
	return (1);
}

void	init_env(char *name, t_env *e)
{
	e->map.name = name;
	e->custom_clr = 0;
	e->map.z_scale = 1;
}

int	main(int ac, char **av)
{
	t_env	env;

	if (WIN_WIDTH < 800 || WIN_HEIGHT < 800
		|| WIN_WIDTH > 2000 || WIN_HEIGHT > 2000)
		return (win_error());
	if (ac != 2)
		return (arg_error());
	init_env(ft_strtrim(av[1], " \f\n\r\t\v"), &env);
	if (!get_map(&env))
		return (0);
	if (!init_mlx(&env))
		return (0);
}
