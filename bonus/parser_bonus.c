/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:30:52 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/20 08:37:12 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_pt(char **pts)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (pts[i])
	{
		if (ft_strlen(pts[i]) > 0 && ft_isdigit(pts[i][0]))
			count++;
		i++;
	}
	return (count);
}

void	set_color(int x, int y, char *color, t_env *e)
{
	char	*clr;

	clr = ft_strchr(color, ',');
	if (clr && ft_strlen(clr) == 9)
	{
		e->custom_clr = 1;
		e->map.clr[y][x] = char_to_rgb(++clr);
	}
	else
		e->map.clr[y][x] = rgb(256, 256, 256);
}

void	save_pt_infos(int y, char **pts, t_env *e)
{
	int			x;
	int			i;
	t_vector3	pt;

	x = 0;
	i = 0;
	while ((pts)[i])
	{
		if (ft_strlen((pts)[x]) > 0 && ft_isdigit((pts)[x][0]))
		{
			pt = vector3(x * 10, y * 10, ft_atoi((pts)[x]));
			e->map.z_min = min(e->map.z_min, pt.z);
			e->map.z_max = max(e->map.z_max, pt.z);
			set_color(x, y, (pts)[x], e);
			e->map.pts[y][x] = pt;
			x++;
		}
		i++;
	}
}

int	line_decoder(int *y, t_env *e)
{
	char		**pts;
	int			i;

	pts = ft_split(e->map.lines[*y], ' ');
	if (*y == 0)
		e->map.x_max = count_pt(pts);
	if (e->map.x_max != count_pt(pts))
		return (map_error(pts, *y, e));
	e->map.pts[*y] = malloc(e->map.x_max * sizeof(t_vector3));
	e->map.clr[*y] = malloc(e->map.x_max * sizeof(t_rgb_color));
	if (!e->map.clr[*y] || !e->map.pts[*y])
		return (0);
	save_pt_infos(*y, pts, e);
	(*y)++;
	i = 0;
	while (pts[i])
	{
		free(pts[i]);
		i++;
	}
	free(pts);
	return (1);
}

int	decode_lines(t_env *e)
{
	int			y;

	y = 0;
	e->map.pts = malloc(e->map.y_max * sizeof(t_vector3 *));
	if (!e->map.pts)
		return (0);
	e->map.clr = malloc(e->map.y_max * sizeof(t_rgb_color *));
	if (!e->map.clr)
		return (0);
	while (y < e->map.y_max)
		if (!line_decoder(&y, e))
			return (0);
	return (1);
}
