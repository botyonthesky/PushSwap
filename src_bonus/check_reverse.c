/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:08:39 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:09:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	check_reverse(t_stack **x)
{
	t_stack	*tmp;
	t_stack	*prev;

	if ((*x) && (*x)->next)
	{
		tmp = (*x);
		prev = NULL;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *x;
		*x = tmp;
	}
}

void	check_rra(t_stack **a)
{
	check_reverse(a);
}

void	check_rrb(t_stack **b)
{
	check_reverse(b);
}

void	check_rrr(t_stack **a, t_stack **b)
{
	check_reverse(a);
	check_reverse(b);
}
