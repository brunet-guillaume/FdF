/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:25:47 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 11:30:16 by gbrunet          ###   ########.fr       */
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

# define ESC_KEY 65307
# define LEFT_CTRL_KEY 65507
# define RIGHT_CTRL_KEY 65508
# define LEFT_SHIFT_KEY 65505
# define RIGHT_SHIFT_KEY 65506
# define CAPS_LOCK_KEY 65509
# define BACKSPACE_KEY 65288
# define RETURN_KEY 65293

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

typedef struct	s_rgb_color {
	int	r;
	int	g;
	int	b;
}	t_rgb_color;

typedef struct	s_map {
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

typedef struct	s_env {
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


int	get_nb_lines(char *file);
int	file_ext(char *f);
int	check_file(t_env *e);
int	get_lines(t_env *e);

int			get_mouse_pos(int x, int y, t_env *e);

void		draw_line(t_vector3 p1, t_vector3 p2, t_rgb_color clr, t_env *e);
void		draw_line_AA(t_vector3 p1, t_vector3 p2, t_rgb_color c1,
	t_rgb_color c2, t_env *e);

void		set_bg(t_env *e, t_rgb_color clr);
void		put_pxl_AA(t_img *img, t_vector3 p, t_rgb_color clr, float bright);
void		put_pxl(t_img *img, t_vector3 p, t_rgb_color clr);

t_rgb_color lerp_clr(t_rgb_color clr1, t_rgb_color clr2, float t);
t_rgb_color rgb(int r, int g, int b);
t_rgb_color char_to_rgb(char *clr);
t_rgb_color	rgb_from_int(int clr);
t_rgb_color clr_from_z(int z, t_env *e);
int			mix_color(t_rgb_color clr, float bright, int back_clr);
int 		int_from_rgb(t_rgb_color clr);
int			hex_val(char c);

int			min(int a, int b);
void		swap(int *a, int *b);
float		fPartOfNb(float x);
float		rfPartOfNb(float x);

t_vector3	rotateX(t_vector3 p, int angle);
t_vector3	rotateY(t_vector3 p, int angle);
t_vector3	rotateZ(t_vector3 p, int angle);

t_vector3	scale_height(t_vector3 p, float s);
t_vector3	scale(t_vector3 p, float s);
t_vector3	center(t_vector3 p, t_env *e);
t_vector3	center_in_view(t_vector3 p);
t_vector3	transform(t_vector3 p, t_env *e);
t_vector3	parallel_tr(t_vector3 p, t_env *e);

int			init_mlx(t_env *e);
int			update(t_env *e);
int			close_win(t_env *e);

int			draw_map(t_env *e);

int			count_pt(char **pts);
void		save_pt_infos(int y, char ***pts, t_env *e);
int			decode_lines(t_env *e);
#endif
