/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:19:19 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:22:26 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exe_ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	exe_rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate(t_stack **x)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *x;
	*x = (*x)->next;
	last = get_last(*x);
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_a(t_stack **a, int *price)
{
	while (*price)
	{
		if (*price > 0)
		{
			exe_ra(a);
			(*price)--;
		}
		else if (*price < 0)
		{
			exe_rra(a);
			(*price)++;
		}
	}
}

void	rotate_b(t_stack **b, int *price)
{
	while (*price)
	{
		if (*price > 0)
		{
			exe_rb(b);
			(*price)--;
		}
		else if (*price < 0)
		{
			exe_rrb(b);
			(*price)++;
		}
	}
}
