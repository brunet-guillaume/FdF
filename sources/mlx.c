/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:18:18 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 18:10:54 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_win(t_env *e)
{
	int	y;

	y = 0;
	while (y < e->map.y_max)
	{
		free(e->map.pts[y]);
		free(e->map.clr[y]);
		y++;
	}
	free(e->map.pts);
	free(e->map.clr);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_display(e->mlx);
	free(e->mlx);
	exit(0);
}

int	update(t_env *e)
{
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	e->img.img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.l_len,
			&e->img.endian);
	mlx_hook(e->win, 17, (1L << 3), close_win, e);
	mlx_hook(e->win, 2, (1L << 0), press_key, e);
	draw_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	mlx_loop(e->mlx);
	return (1);
}
