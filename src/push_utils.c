/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:46:03 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:56:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_stack *x)
{
	t_stack	*tmp;
	int		count;

	tmp = x;
	count = 0;
	if (tmp == NULL)
		return (count);
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	get_bigger(t_stack *x)
{
	int	idx;

	idx = x->i;
	while (x)
	{
		if (x->i > idx)
			idx = x->i;
		x = x->next;
	}
	return (idx);
}

int	is_sort(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (KO);
		tmp = tmp->next;
	}
	return (OK);
}

void	define_idx(t_stack *a, int size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		tmp = a;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->i == 0)
				tmp->i = 1;
			if (tmp->value > value && tmp->i == 0)
			{
				value = tmp->value;
				highest = tmp;
				tmp = a;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->i = size;
	}
}
