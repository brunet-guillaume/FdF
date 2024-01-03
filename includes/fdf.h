/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:25:47 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/20 09:07:06 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "fdf_struct.h"
# include <math.h>
# include <stdlib.h>
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

int			toggle(int i);
int			hex_val(char c);
int			win_error(void);
int			arg_error(void);
int			update(t_env *e);
int			file_error(void);
int			read_error(void);
int			file_ext(char *f);
int			min(int a, int b);
int			draw_map(t_env *e);
int			init_mlx(t_env *e);
int			close_win(t_env *e);
int			get_lines(t_env *e);
int			count_pt(char **pts);
int			check_file(t_env *e);
int			decode_lines(t_env *e);
int			get_nb_lines(char *file);
int			int_from_rgb(t_rgb_color clr);
int			up_key(int keycode, t_env *e);
int			press_key(int keycode, t_env *e);
int			get_mouse_pos(int x, int y, t_env *e);
int			map_error(char **pts, int y, t_env *e);
int			mouse_hook(int btn, int x, int y, t_env *e);
int			mix_color(t_rgb_color clr, float bright, int back_clr);
void		draw_clrs(t_env *e);
void		update_pan(t_env *e);
void		swap(int *a, int *b);
void		reset_view(t_env *e);
void		update_zoom(t_env *e);
void		draw_parallel(t_env *e);
void		update_rotation(t_env *e);
void		set_bg(t_env *e, t_rgb_color clr);
void		change_z_scale(int coef, t_env *e);
void		check_click(int x, int y, t_env *e);
void		draw_line_aa(t_line_infos line, t_env *e);
void		save_pt_infos(int y, char **pts, t_env *e);
void		draw_clr(t_vector2 pt, t_rgb_color clr, t_env *e);
void		put_pxl(t_img *img, t_vector3 p, t_rgb_color clr);
void		draw_line(t_vector3 p1, t_vector3 p2, t_rgb_color clr, t_env *e);
void		put_pxl_aa(t_img *img, t_vector3 p, t_rgb_color clr, float bright);
float		fpartofnb(float x);
float		rfpartofnb(float x);
double		d_max(double a, double b);
double		d_min(double a, double b);
t_vector2	vector2(int x, int y);
t_vector3	center_in_view(t_vector3 p);
t_vector3	scale(t_vector3 p, float s);
t_vector3	scale(t_vector3 p, float s);
t_vector3	vector3(int x, int y, int z);
t_vector3	center(t_vector3 p, t_env *e);
t_vector3	transform(t_vector3 p, t_env *e);
t_vector3	rotate_x(t_vector3 p, int angle);
t_vector3	rotate_y(t_vector3 p, int angle);
t_vector3	rotate_z(t_vector3 p, int angle);
t_vector3	scale_height(t_vector3 p, float s);
t_vector3	parallel_tr(t_vector3 p, t_env *e);
t_rgb_color	rgb_from_int(int clr);
t_rgb_color	char_to_rgb(char *clr);
t_rgb_color	rgb(int r, int g, int b);
t_rgb_color	clr_from_z(int z, t_env *e);
t_rgb_color	lerp_clr(t_rgb_color clr1, t_rgb_color clr2, float t);

#endif
