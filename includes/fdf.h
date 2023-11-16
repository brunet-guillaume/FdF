/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:25:47 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/16 11:15:06 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h> // a remplacer par ft_printf
# include <fcntl.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1920
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1080
# endif

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_img;

typedef struct	s_vector2 {
	int	x;
	int	y;
}	t_vector2;

typedef struct	s_vector3 {
	int	x;
	int	y;
	int	z;
}	t_vector3;

typedef struct	s_map {
	char	*name;
	char	**lines;
	int		x_max;
	int		y_max;
	int		**p;
}	t_map;

typedef struct	s_env {
	void		*mlx;
	void		*win;
	t_img		img;
	t_vector2	mouse_pos;
	t_map		map;
}	t_env;

typedef struct	s_rgb_color {
	int	r;
	int	g;
	int	b;
}	t_rgb_color;

typedef struct	s_line_AA {
	int			steep;
	float		dx;
	float		dy;
	float		gradient;
	int			xpx1;
	int			xpx2;
	float		intY;
	int			x;
	t_vector3	p;
}	t_line_AA;

typedef struct	s_line {
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	err2;
}	t_line;



int			get_mouse_pos(int x, int y, t_env *e);

void		draw_line(t_vector3 p1, t_vector3 p2, t_rgb_color clr, t_env e);
void		draw_line_AA(t_vector3 p1, t_vector3 p2, t_rgb_color clr, t_env e);

void		set_bg(t_env *e, t_rgb_color clr);
void		put_pxl_AA(t_img *img, t_vector3 p, t_rgb_color clr, float bright);
void		put_pxl(t_img *img, t_vector3 p, t_rgb_color clr);

t_rgb_color rgb(int r, int g, int b);
int			mix_color(t_rgb_color clr, float bright, int back_clr);
t_rgb_color	rgb_from_int(int clr);
int 		int_from_rgb(t_rgb_color clr);

int			min(int a, int b);
void		swap(int *a, int *b);
float		fPartOfNb(float x);
float		rfPartOfNb(float x);

t_vector3	rotateX(t_vector3 p, int angle);
t_vector3	rotateY(t_vector3 p, int angle);
t_vector3	rotateZ(t_vector3 p, int angle);

t_vector3	center(t_vector3 p);

#endif
