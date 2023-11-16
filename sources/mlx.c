/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:18:18 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/16 18:23:56 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
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
	e->mouse_pos.x = 0;
	e->mouse_pos.y = WIN_HEIGHT / 2;
	mlx_hook(e->win, 17, (1L<<3), close_win, e);	
	mlx_hook(e->win, 6, (1L << 6), get_mouse_pos, e);
	mlx_loop_hook(e->mlx, update, e);
	mlx_loop(e->mlx);
	return (1);
}
