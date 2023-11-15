/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:57:26 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/15 20:00:47 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector3	center(t_vector3 p)
{
	t_vector3	centered;
	centered.x = p.x + WIN_WIDTH / 2;
	centered.y = p.y + WIN_HEIGHT / 2;
	centered.z = 0;
	return (centered);
}
