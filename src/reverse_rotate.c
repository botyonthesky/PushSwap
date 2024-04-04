/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:44:48 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:56:58 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exe_rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	reverse_rotate(t_stack **x)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*previous_last;

	last = get_last(*x);
	previous_last = get_previous_last(*x);
	tmp = *x;
	*x = last;
	(*x)->next = tmp;
	previous_last->next = NULL;
}

void	exe_rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	exe_rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

void	exe_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
