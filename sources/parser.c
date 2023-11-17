/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:30:52 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 15:41:25 by gbrunet          ###   ########.fr       */
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

void	save_pt_infos(int y, char ***pts, t_env *e)
{
	int			x;
	int			i;
	t_vector3	pt;
	char		*clr;

	x = 0;
	i = 0;
	while ((*pts)[i])
	{
		if (ft_strlen((*pts)[x]) > 0 && ft_isdigit((*pts)[x][0]))
		{
			pt.x = x * 10;
			pt.y = y * 10;
			pt.z = ft_atoi((*pts)[x]);
			e->map.z_min = min(e->map.z_min, pt.z);
			e->map.z_max = max(e->map.z_max, pt.z);
			clr = ft_strchr((*pts)[x], ',');
			if (clr && ft_strlen(clr) == 9)
			{
				e->custom_clr = 1;
				e->map.clr[y][x] = char_to_rgb(++clr);
			}
			else
				e->map.clr[y][x] = rgb(256, 256, 256);
			e->map.pts[y][x] = pt;
			x++;
		}
		i++;
	}
}

int	decode_lines(t_env *e)
{
	char		**pts;
	int			y;
	int			i;

	y = 0;
	e->map.pts = malloc(e->map.y_max * sizeof(t_vector3 *));
	if (!e->map.pts)
		return (0);
	e->map.clr = malloc(e->map.y_max * sizeof(t_rgb_color *));
	if (!e->map.clr)
		return (0);
	while (y < e->map.y_max)
	{
		pts = ft_split(e->map.lines[y], ' ');
		if (y == 0)
			e->map.x_max = count_pt(pts);
		if (e->map.x_max != count_pt(pts))
		{
			i = 0;
			while (pts[i])
			{
				free(pts[i]);
				i++;
			}
			free(pts);
			while (--y >= 0)
			{
				free(e->map.pts[y]);
				free(e->map.clr[y]);
			}
			free(e->map.pts);
			free(e->map.clr);
			ft_putstr_fd("Erreur. Map non conforme.\n", 2);
			return (0);
		}
		e->map.pts[y] = malloc(e->map.x_max * sizeof(t_vector3));
		e->map.clr[y] = malloc(e->map.x_max * sizeof(t_rgb_color));
		if (!e->map.clr[y] || !e->map.pts[y])
			return (0);
		save_pt_infos(y, &pts, e);
		y++;
		i = 0;
		while (pts[i])
		{
			free(pts[i]);
			i++;
		}
		free(pts);
	}
	return (1);
}
