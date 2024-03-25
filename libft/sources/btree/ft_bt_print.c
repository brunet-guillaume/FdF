/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bt_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:27:11 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/02 21:44:55 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bt_print_child(t_btree *n, int pad[1024], int d, void (*p)(void *))
{
	int	i;

	if (!n)
		return ;
	i = -1;
	while (++i < d - 1)
	{
		if (pad[i])
			ft_printf("  │  ");
		else
			ft_printf("     ");
	}
	if (pad[d - 1] == 1)
		ft_printf("  ├─ ");
	else
		ft_printf("  └─ ");
	(*p)(n->data);
	ft_printf("\n");
	if (n->right)
		pad[d] = 1;
	ft_bt_print_child(n->left, pad, d + 1, p);
	pad[d] = 0;
	ft_bt_print_child(n->right, pad, d + 1, p);
}

void	ft_bt_print(t_btree *root, void (*print)(void *))
{
	int	paddings[1024];
	int	depth;

	depth = 0;
	if (!root)
		return ;
	ft_bzero(&paddings, sizeof(int) * 1024);
	ft_printf("Binary tree %p\n", root);
	(*print)(root->data);
	ft_printf("\n");
	if (root->right)
		paddings[depth] = 1;
	ft_bt_print_child(root->left, paddings, depth + 1, print);
	paddings[depth] = 0;
	ft_bt_print_child(root->right, paddings, depth + 1, print);
}
