/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:09:52 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:11:05 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	check_rotate(t_stack **x)
{
	t_stack	*first;
	t_stack	*last;

	if (*x == NULL || (*x)->next == NULL)
		return ;
	first = *x;
	last = *x;
	first = (*x)->next;
	last = *x;
	while (last->next)
		last = last->next;
	last->next = *x;
	(*x)->next = NULL;
	*x = first;
}

void	check_ra(t_stack **a)
{
	check_rotate(a);
}

void	check_rb(t_stack **b)
{
	check_rotate(b);
}

void	check_rr(t_stack **a, t_stack **b)
{
	check_rotate(a);
	check_rotate(b);
}
