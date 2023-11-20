/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:06:00 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/20 09:09:50 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_img;

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
	int	g;
	int	b;
}	t_rgb_color;

typedef struct s_map {
	char		*name;
	char		**lines;
	int			x_max;
	int			y_max;
	t_vector3	**pts;
	t_rgb_color	**clr;
	int			z_min;
	int			z_max;
	float		z_scale;
}	t_map;

typedef struct s_env {
	void		*mlx;
	void		*win;
	t_img		img;
	t_vector2	mouse_pos_init;
	t_vector2	mouse_pos;
	t_vector2	rotation_init;
	t_vector2	rotation;
	t_vector2	pan_init;
	t_vector2	pan;
	float		zoom_init;
	float		zoom;
	t_map		map;
	int			ctrl_down;
	int			shift_down;
	int			caps_lock_down;
	int			custom_clr;
	t_rgb_color	clr_bottom;
	t_rgb_color	clr_top;
	int			parallel;
}	t_env;

typedef struct s_line_aa {
	int			steep;
	float		dx;
	float		dy;
	float		gradient;
	int			xpx1;
	int			xpx2;
	float		int_y;
	int			x;
	t_vector3	p;
}	t_line_aa;

typedef struct s_line_infos {
	t_vector3	p1;
	t_vector3	p2;
	t_rgb_color	c1;
	t_rgb_color	c2;
}	t_line_infos;

typedef struct s_line {
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	err2;
}	t_line;

#endif
