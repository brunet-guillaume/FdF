/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:19:54 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/16 12:33:43 by gbrunet          ###   ########.fr       */
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

int	get_nb_lines(char *file)
{
	int		fd;
	char	*line;
	int		i;
	
	fd = open(file, O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)))
		i++;
	close(fd);
	return (i);
}

int	file_ext(char *f)
{
	int	i;

	i = ft_strlen(f);
	if (f[i - 4] == '.' && f[i - 3] == 'f'
		&& f[i - 2] == 'd' && f[i - 1] == 'f')
		return (1);
	return (0);
}

int	check_file(t_env *e)
{
	int		fd;
	char	*line;

	if (!file_ext(e->map.name))
	{
		ft_putstr_fd("Erreur. Format de fichier incorrect.\n", 2);
		return (0);
	}
	fd = open(e->map.name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Erreur. Impossible d'ouvrir le fichier.\n", 2);
		return (0);
	}
	e->map.y_max = 0;
	while ((line = get_next_line(fd)))
		e->map.y_max++;
	if (e->map.y_max == 0)
	{
		ft_putstr_fd("Erreur. Le fichier est vide.\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

int	get_lines(t_env *e)
{
	int	fd;
	int	i;

	e->map.lines = malloc(e->map.y_max * sizeof(char*));
	if (!e->map.lines)
		return (0);
	fd = open(e->map.name, O_RDONLY);
	i = 0;
	while (i < e->map.y_max)
	{
		e->map.lines[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	count_pt(char **pts)
{
	int	i;

	i = 0;
	while (pts[i])
		i++;
	return (i);
}

int	decode_lines(t_env *e)
{
	char	**pts;
	char	x_max;
	int		i;
	int		j;

	x_max = -1;
	i = 0;
	e->map.p = malloc(e->map.y_max * sizeof(int *));
	if (!e->map.p)
		return (0);
	while (i < e->map.y_max)
	{
		pts = ft_split(e->map.lines[i], ' ');
		if (x_max == -1)
		{
			x_max = count_pt(pts);
			e->map.x_max = x_max;
		}
		else if (x_max != count_pt(pts))
		{
			ft_putstr_fd("Erreur. Map non conforme.\n", 2);
			return (0);
		}
		e->map.p[i] = malloc(x_max * sizeof(int));
		if (!e->map.p[i])
			return (0);
		j = 0;
		while (j < x_max)
		{
			e->map.p[i][j] = ft_atoi(pts[j]);
			j++;
		}
		i++;
	}
	return (1);
}

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

int	close_win(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

int	init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	e->img.img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->img.addr = mlx_get_data_addr(e->img.img, &e->img.bpp, &e->img.l_len,
		&e->img.endian);
	e->mouse_pos.x = 0;
	e->mouse_pos.y = 0;
	mlx_hook(e->win, 17, (1L<<3), close_win, e);
	mlx_loop(e->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_env	env;
	
	if (WIN_WIDTH < 1 || WIN_HEIGHT < 1 ||
		WIN_WIDTH > 2000 || WIN_HEIGHT > 2000)
	{
		ft_putstr_fd("Erreur. Taille de la fenetre non conforme.\n", 2);
		ft_putstr_fd("Hauteur et largeur doivent etre entre 1 et 2000px.\n", 2);
		return (0);
	}
	if (ac != 2)
	{
		ft_putstr_fd("Erreur. Veuillez donner une seule map au format .fdf", 2);
		ft_putstr_fd(" en argument de ce programme\n", 2);
		return (0);
	}
	env.map.name = ft_strtrim(av[1], " \f\n\r\t\v");
	if (!get_map(&env))
		return (0);
	if (!init_mlx(&env))
		return (0);
	return (0);
}

/*
int	main(void)
{
	mlx_hook(env.win, 6, (1L << 6), get_mouse_pos, &env);
	mlx_loop_hook(env.mlx, update, &env);
	mlx_loop(env.mlx);
	return (0);	
}*/
