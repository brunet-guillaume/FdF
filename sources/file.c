/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:28:20 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/16 18:28:34 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
