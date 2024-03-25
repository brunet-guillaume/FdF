/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_add_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:04:40 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/02 13:05:02 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_bt_add_left(t_btree *root, void *data)
{
	if (!root)
		return (NULL);
	root->left = ft_bt_new(data);
	return (root->left);
}
