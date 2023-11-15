/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:20:02 by gbrunet           #+#    #+#             */
/*   Updated: 2023/11/15 20:55:42 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pxl_AA(t_img *img, t_vector3 p, t_rgb_color clr, float bright)
{
	char	*dst;
	
	if (p.x < 0 || p.y < 0 ||
		p.x > WIN_WIDTH - 1 || p.y > WIN_HEIGHT - 1)
		return ;
	dst = img->addr + (p.y * img->l_len + p.x * (img->bpp / 8));
	*(unsigned int*)dst = mix_color(clr, bright, *(unsigned int*)dst);
}

void	put_pxl(t_img *img, t_vector3 p, t_rgb_color clr)
{
	char	*dst;

	if (p.x < 0 || p.y < 0 ||
		p.x > WIN_WIDTH - 1 || p.y > WIN_HEIGHT - 1)
		return ;
	dst = img->addr + (p.y * img->l_len + p.x * (img->bpp / 8));
	*(unsigned int*)dst = int_from_rgb(clr);
}

void	set_bg(t_env *e, t_rgb_color clr)
{
	t_vector3	p;

	p.x = 0;
	p.y = 0;
	while (p.y < WIN_HEIGHT)
	{
		p.x = 0;
		while (p.x < WIN_WIDTH)
		{
			put_pxl(&e->img, p, clr);
			p.x++;
		}
		p.y++;
	}
}
