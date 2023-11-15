/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:54 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/15 19:12:30 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef WIN_WIDTH
# define WIN_WIDTH 1920
#endif
#ifndef WIN_HEIGTH
# define WIN_HEIGHT 1080
#endif

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_img;

typedef struct s_env {
	void	*mlx;
	void	*win;
	t_img	img;
	int		mouse_x;
	int		mouse_y;
}	t_env;

typedef struct s_vector2 {
	int	x;
	int	y;
}	t_vector2;

typedef struct s_vector3 {
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct s_rgb_color {
	int	r;
	int g;
	int b;
}	t_rgb_color;

typedef struct s_matrix3x3 {
	t_vector3	a;
	t_vector3	b;
	t_vector3	c;
}	t_matrix3_3;

t_vector3	rotateX(t_vector3 p, int angle)
{
	t_vector3	rotated;

	float rad = angle * M_PI / 180;
	rotated.x = p.x;
	rotated.y = cos(rad) * p.y - sin(rad) * p.z;
	rotated.z = sin(rad) * p.y + cos(rad) * p.z;
	return (rotated);
}

t_vector3	rotateY(t_vector3 p, int angle)
{
	t_vector3	rotated;

	float rad = angle * M_PI / 180;
	rotated.x = p.x * cos(rad) + p.z * sin(rad);
	rotated.y = p.y;
	rotated.z = -sin(rad) * p.x + p.z * cos(rad);
	return (rotated);
}

t_vector3	rotateZ(t_vector3 p, int angle)
{
	t_vector3	rotated;

	float rad = angle * M_PI / 180;
	rotated.x = p.x * cos(rad) - p.y * sin(rad);
	rotated.y = p.x * sin(rad) + p.y * cos(rad);
	rotated.z = p.z;
	return (rotated);
}

t_vector3	center(t_vector3 p)
{
	t_vector3	centered;

	centered.x = p.x + WIN_WIDTH / 2;
	centered.y = p.y + WIN_HEIGHT / 2;
	return (centered);
}


int min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	rgb_bright(t_rgb_color color, float brightness, int back_color)
{
	t_rgb_color	back_rgb;

	back_rgb.r = (back_color >> 16 & 0xFF);
	back_rgb.g = (back_color >> 8 & 0xFF);
	back_rgb.b = (back_color & 0xFF);
	return ((min(max(back_rgb.r * (1 - brightness) + brightness * color.r, 0), 255) << 16) +
		(min(max(back_rgb.g * (1 - brightness) + brightness * color.g, 0), 255) << 8) +
		(min(max(back_rgb.b * (1 - brightness) + brightness * color.b, 0), 255)));
}

void	put_pixelAA(t_img *img, int x, int y, t_rgb_color color, float brightness)
{
	char	*dst;
	
	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int*)dst = rgb_bright(color, brightness, *(unsigned int*)dst);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

float	fPartOfNb(float x)
{
	if (x > 0)
		return (x - (int)x);
	return (x - ((int)x + 1));
}

float	rfPartOfNb(float x)
{
	return (1 - fPartOfNb(x));
}

void	draw_AAline(t_vector3 p1, t_vector3 p2, t_rgb_color color, t_env e)
{
	int		steep;
	float	dx;
	float	dy;
	float	gradient;
	int		xpx1;
	int		xpx2;
	float	intY;
	int		x;

	steep = 0;
	if (abs(p2.y - p1.y) > abs(p2.x - p1.x))
		steep = 1;
	if (steep)
	{
		swap(&p1.x, &p1.y);
		swap(&p2.x, &p2.y);
	}
	if (p1.x > p2.x)
	{
		swap(&p1.x, &p2.x);
		swap(&p1.y, &p2.y);
	}
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	gradient = dy / dx;
	if (dx == 0.0)
		gradient = 1;
	xpx1 = p1.x;
	xpx2 = p2.x;
	intY = p1.y;
	x = xpx1;
	if(steep)
	{
		while (x <= xpx2)
		{
			put_pixelAA(&e.img, (int)intY, x, color, fPartOfNb(intY));
			put_pixelAA(&e.img, (int)intY - 1, x, color, rfPartOfNb(intY));
			intY += gradient;
			x++;
		}
	}
	else
	{
		while(x <= xpx2)
		{
			put_pixelAA(&e.img, x, (int)intY, color, fPartOfNb(intY));
			put_pixelAA(&e.img, x, (int)intY - 1, color, rfPartOfNb(intY));
			intY += gradient;
			x++;
		}
	}
}

void	draw_line(t_vector3 p1, t_vector3 p2, int color, t_env e)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	err2;

	dx = abs(p2.x - p1.x);
	sx = 1;
	if (p1.x > p2.x)
		sx = -1;
	dy = -abs(p2.y - p1.y);
	sy = 1;
	if (p1.y > p2.y)
		sy = -1;
	err =  dx + dy;
	while (!(p2.x == p1.x && p2.y == p1.y))
	{
		put_pixel(&e.img, p1.x + 200, p1.y + 200, color);
		err2 = 2 * err;
		if (err2 >= dy)
		{
			err += dy;
			p1.x += sx;
		}
		if (err2 <= dx)
		{
			err += dx;
			p1.y += sy;
		}
	}
}

int	get_mouse_pos(int x, int y, t_env *e)
{
	e->mouse_x = x;
	e->mouse_y = y;
	return (0);
}

t_rgb_color rgb(int r, int g, int b)
{
	t_rgb_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void	clear_bg(t_env *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(&e->img, x , y, 0x00333333);
			x++;
		}
		y++;
	}
}

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
	
	p1 = rotateZ(p1, -e->mouse_x/5);
	p2 = rotateZ(p2, -e->mouse_x/5);
	p3 = rotateZ(p3, -e->mouse_x/5);
	p4 = rotateZ(p4, -e->mouse_x/5);
	p5 = rotateZ(p5, -e->mouse_x/5);
	p6 = rotateZ(p6, -e->mouse_x/5);
	p7 = rotateZ(p7, -e->mouse_x/5);
	p8 = rotateZ(p8, -e->mouse_x/5);

	p1 = rotateY(p1, -e->mouse_y/5);
	p2 = rotateY(p2, -e->mouse_y/5);
	p3 = rotateY(p3, -e->mouse_y/5);
	p4 = rotateY(p4, -e->mouse_y/5);
	p5 = rotateY(p5, -e->mouse_y/5);
	p6 = rotateY(p6, -e->mouse_y/5);
	p7 = rotateY(p7, -e->mouse_y/5);
	p8 = rotateY(p8, -e->mouse_y/5);
	
	p1 = center(p1);
	p2 = center(p2);
	p3 = center(p3);
	p4 = center(p4);
	p5 = center(p5);
	p6 = center(p6);
	p7 = center(p7);
	p8 = center(p8);

	clear_bg(e);

	draw_AAline(p1, p2, rgb(255, 128, 0), *e);
	draw_AAline(p2, p4, rgb(255, 128, 0), *e);
	draw_AAline(p4, p3, rgb(255, 128, 0), *e);
	draw_AAline(p3, p1, rgb(255, 128, 0), *e);
	draw_AAline(p5, p6, rgb(255, 128, 0), *e);
	draw_AAline(p6, p8, rgb(255, 128, 0), *e);
	draw_AAline(p8, p7, rgb(255, 128, 0), *e);
	draw_AAline(p7, p5, rgb(255, 128, 0), *e);
	draw_AAline(p1, p5, rgb(255, 128, 0), *e);
	draw_AAline(p2, p6, rgb(255, 128, 0), *e);
	draw_AAline(p4, p8, rgb(255, 128, 0), *e);
	draw_AAline(p3, p7, rgb(255, 128, 0), *e);

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
	env.mouse_x = 0;
	env.mouse_y = 0;

	mlx_hook(env.win, 6, (1L << 6), get_mouse_pos, &env);
	mlx_loop_hook(env.mlx, update, &env);
	mlx_loop(env.mlx);
	
}
