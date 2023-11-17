/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:54 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 11:54:20 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#include <stdio.h>

int	get_map(t_env *e)
{
	if (!check_file(e))
		return (0);
	if (!get_lines(e))
		return (0);
	if (!decode_lines(e))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;
	
	if (WIN_WIDTH < 800 || WIN_HEIGHT < 800 ||
		WIN_WIDTH > 2000 || WIN_HEIGHT > 2000)
	{
		ft_putstr_fd("Erreur. Taille de la fenetre non conforme.\n", 2);
		ft_putstr_fd("Hauteur et largeur doivent etre entre", 2);
		ft_putstr_fd(" 800 et 2000px.\n", 2);
		return (0);
	}
	if (ac != 2)
	{
		ft_putstr_fd("Erreur. Veuillez donner une seule map au format .fdf", 2);
		ft_putstr_fd(" en argument de ce programme\n", 2);
		return (0);
	}
	env.map.name = ft_strtrim(av[1], " \f\n\r\t\v");
	env.custom_clr = 0;
	env.clr_bottom = rgb(255, 0, 0);
	env.clr_top = rgb(128, 255, 0);
	env.parallel = 0;
	env.map.z_min = 0;
	env.map.z_max = 0;
	env.map.z_scale = 1;
	if (!get_map(&env))
		return (0);
	if (!init_mlx(&env))
		return (0);
	return (0);
}
