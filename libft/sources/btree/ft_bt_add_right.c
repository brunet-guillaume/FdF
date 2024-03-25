/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_add_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:05:21 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/02 13:05:31 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_bt_add_right(t_btree *root, void *data)
{
	if (!root)
		return (NULL);
	root->right = ft_bt_new(data);
	return (root->right);
}
