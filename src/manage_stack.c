/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:58:03 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 06:59:21 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_last(t_stack *x)
{
	while (x && x->next != NULL)
		x = x->next;
	return (x);
}

t_stack	*get_previous_last(t_stack *x)
{	
	while (x && x->next && x->next->next != NULL)
		x = x->next;
	return (x);
}

void	fill_by_end(t_stack **a, t_stack *new)
{
	t_stack	*end;

	if (new == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	end = get_last(*a);
	end->next = new;
}
