/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:52:14 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 06:53:47 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exe_ps_cmd(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && is_sort(*a) == KO)
		exe_sa(a);
	else if (size == 3)
		little_sort(a);
	else if (size > 3 && is_sort(*a) == KO)
		real_sort(a, b);
}

void	little_sort(t_stack **x)
{
	int	bigger_idx;

	if (is_sort(*x) == OK)
		return ;
	bigger_idx = get_bigger(*x);
	if ((*x)->i == bigger_idx)
		exe_ra(x);
	else if ((*x)->next->i == bigger_idx)
		exe_rra(x);
	if ((*x)->i > (*x)->next->i)
		exe_sa(x);
}

void	real_sort(t_stack **a, t_stack **b)
{
	add_to_until_last_three(a, b);
	little_sort(a);
	while (*b)
	{
		manage_position(a, b);
		find_price(a, b);
		find_best_price(a, b);
	}
	if (is_sort(*a) == KO)
		find_best_rotate(a);
}
