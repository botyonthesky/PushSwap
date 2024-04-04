/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:39:05 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:57:24 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *x)
{
	int	tmp;

	if (x == NULL || x->next == NULL)
		return ;
	tmp = x->value;
	x->value = x->next->value;
	x->next->value = tmp;
	tmp = x->i;
	x->i = x->next->i;
	x->next->i = tmp;
}

void	exe_sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	exe_sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}
