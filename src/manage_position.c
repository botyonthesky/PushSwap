/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:40:50 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 06:44:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	manage_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		position;

	tmp = *b;
	find_position(a);
	find_position(b);
	position = 0;
	while (tmp)
	{
		position = extract_position(a, tmp->i, INT_MAX, position);
		tmp->goal_pos = position;
		tmp = tmp->next;
	}
}

int	extract_position(t_stack **a, int tmp_i, int max, int pos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->i > tmp_i && tmp->i < max)
		{
			max = tmp->i;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (max != INT_MAX)
		return (pos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->i < max)
		{
			max = tmp->i;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}

void	find_position(t_stack **x)
{
	t_stack	*tmp;
	int		i;

	tmp = *x;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
