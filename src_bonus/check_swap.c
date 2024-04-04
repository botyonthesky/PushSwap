/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:54:20 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 17:55:16 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	check_swap(t_stack **x)
{
	int	tmp;

	if (!(*x) || (!(*x)->next))
		return ;
	tmp = (*x)->value;
	(*x)->value = (*x)->next->value;
	(*x)->next->value = tmp;
	tmp = (*x)->i;
	(*x)->i = (*x)->next->i;
	(*x)->next->i = tmp;
}

void	check_ss(t_stack **a, t_stack **b)
{
	check_swap(a);
	check_swap(b);
}
