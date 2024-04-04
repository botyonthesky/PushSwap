/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:59:56 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:02:16 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_best_rotate(t_stack **a)
{
	int	best_pos;
	int	size;

	size = stack_size(*a);
	best_pos = get_best(a);
	if (best_pos > size / 2)
	{
		while (best_pos < size)
		{
			exe_rra(a);
			best_pos++;
		}
	}
	else
	{
		while (best_pos > 0)
		{
			exe_ra(a);
			best_pos--;
		}
	}
}

int	get_best(t_stack **x)
{
	t_stack	*tmp;
	int		best_idx;
	int		best_pos;

	tmp = *x;
	best_idx = INT_MAX;
	find_position(x);
	best_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->i < best_idx)
		{
			best_idx = tmp->i;
			best_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (best_pos);
}
