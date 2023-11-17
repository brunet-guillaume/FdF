/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:00:51 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 18:19:59 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	file_error(void)
{
	ft_putstr_fd("Erreur. Format de fichier incorrect.\n", 2);
	return (0);
}

int	read_error(void)
{
	ft_putstr_fd("Erreur. Impossible d'ouvrir le fichier.\n", 2);
	return (0);
}

int	win_error(void)
{
	ft_putstr_fd("Erreur. Taille de la fenetre non conforme.\n", 2);
	ft_putstr_fd("Hauteur et largeur doivent etre entre", 2);
	ft_putstr_fd(" 800 et 2000px.\n", 2);
	return (0);
}

int	arg_error(void)
{
	ft_putstr_fd("Erreur. Veuillez donner une seule map au format .fdf", 2);
	ft_putstr_fd(" en argument de ce programme\n", 2);
	return (0);
}
