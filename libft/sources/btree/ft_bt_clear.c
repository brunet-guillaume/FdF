/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:06:14 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/02 13:06:24 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bt_clear(t_btree	*root, void (*del)(void *))
{
	t_btree	*left;
	t_btree	*right;

	left = root->left;
	if (left)
		ft_bt_clear(left, del);
	right = root->right;
	if (right)
		ft_bt_clear(right, del);
	ft_bt_del(root, del);
}
