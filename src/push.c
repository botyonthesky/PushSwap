/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:17:45 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:19:09 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	manage_push(t_stack **a, t_stack **b, int size, int is_push)
{
	while ((size - is_push) > 3)
	{
		exe_pb(a, b);
		is_push++;
	}
}

void	exe_pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	exe_pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}
