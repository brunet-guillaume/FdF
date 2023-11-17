/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:48:16 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/17 17:50:48 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector3	scale_height(t_vector3 p, float s)
{
	t_vector3	scaled;

	scaled.x = p.x;
	scaled.y = p.y;
	scaled.z = p.z * s;
	return (scaled);
}

t_vector3	scale(t_vector3 p, float s)
{
	t_vector3	scaled;

	scaled.x = p.x * s;
	scaled.y = p.y * s;
	scaled.z = p.z * s;
	return (scaled);
}
