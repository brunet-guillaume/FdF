/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:54 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/15 21:35:12 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	update(t_env *e)
{
	t_vector3 p1;
	t_vector3 p2;
	t_vector3 p3;
	t_vector3 p4;
	t_vector3 p5;
	t_vector3 p6;
	t_vector3 p7;
	t_vector3 p8;

	p1.x = -100;
	p1.y = -100;
	p1.z = 0;

	p2.x = 100;
	p2.y = -100;
	p2.z = 0;
	
	p3.x = -100;
	p3.y = 100;
	p3.z = 0;
	
	p4.x = 100;
	p4.y = 100;
	p4.z = 0;
	
	p5.x = -100;
	p5.y = -100;
	p5.z = 100;
	
	p6.x = 100;
	p6.y = -100;
	p6.z = 100;
	
	p7.x = -100;
	p7.y = 100;
	p7.z = 100;
	
	p8.x = 100;
	p8.y = 100;
	p8.z = 100;
	
	p1 = rotateZ(p1, -e->mouse_pos.x/5);
	p2 = rotateZ(p2, -e->mouse_pos.x/5);
	p3 = rotateZ(p3, -e->mouse_pos.x/5);
	p4 = rotateZ(p4, -e->mouse_pos.x/5);
	p5 = rotateZ(p5, -e->mouse_pos.x/5);
	p6 = rotateZ(p6, -e->mouse_pos.x/5);
	p7 = rotateZ(p7, -e->mouse_pos.x/5);
	p8 = rotateZ(p8, -e->mouse_pos.x/5);

	p1 = rotateY(p1, -e->mouse_pos.y/5);
	p2 = rotateY(p2, -e->mouse_pos.y/5);
	p3 = rotateY(p3, -e->mouse_pos.y/5);
	p4 = rotateY(p4, -e->mouse_pos.y/5);
	p5 = rotateY(p5, -e->mouse_pos.y/5);
	p6 = rotateY(p6, -e->mouse_pos.y/5);
	p7 = rotateY(p7, -e->mouse_pos.y/5);
	p8 = rotateY(p8, -e->mouse_pos.y/5);
	
	p1 = center(p1);
	p2 = center(p2);
	p3 = center(p3);
	p4 = center(p4);
	p5 = center(p5);
	p6 = center(p6);
	p7 = center(p7);
	p8 = center(p8);

	set_bg(e, rgb(70, 70, 70));

	draw_line_AA(p1, p2, rgb(255, 128, 0), *e);
	draw_line_AA(p2, p4, rgb(255, 128, 0), *e);
	draw_line_AA(p4, p3, rgb(255, 128, 0), *e);
	draw_line_AA(p3, p1, rgb(255, 128, 0), *e);
	draw_line_AA(p5, p6, rgb(255, 128, 0), *e);
	draw_line_AA(p6, p8, rgb(255, 128, 0), *e);
	draw_line_AA(p8, p7, rgb(255, 128, 0), *e);
	draw_line_AA(p7, p5, rgb(255, 128, 0), *e);
	draw_line_AA(p1, p5, rgb(255, 128, 0), *e);
	draw_line_AA(p2, p6, rgb(255, 128, 0), *e);
	draw_line_AA(p4, p8, rgb(255, 128, 0), *e);
	draw_line_AA(p3, p7, rgb(255, 128, 0), *e);

	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);

	return (0);
}

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	env.img.img = mlx_new_image(env.mlx, WIN_WIDTH, WIN_HEIGHT);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bpp, &env.img.l_len,
		&env.img.endian);
	env.mouse_pos.x = 0;
	env.mouse_pos.y = 0;

	mlx_hook(env.win, 6, (1L << 6), get_mouse_pos, &env);
	mlx_loop_hook(env.mlx, update, &env);
	mlx_loop(env.mlx);
	
}
