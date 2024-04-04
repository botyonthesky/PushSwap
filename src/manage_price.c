/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_price.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:22:40 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 06:38:50 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_price(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		size;
	int		size2;

	tmp = *a;
	tmp2 = *b;
	size = stack_size(tmp);
	size2 = stack_size(tmp2);
	while (tmp2)
	{
		tmp2->price_b = tmp2->pos;
		if (tmp2->pos > size2 / 2)
			tmp2->price_b = (size2 - tmp2->pos) * -1;
		tmp2->price_a = tmp2->goal_pos;
		if (tmp2->goal_pos > size / 2)
			tmp2->price_a = (size - tmp2->goal_pos) * -1;
		tmp2 = tmp2->next;
	}
}

void	find_best_price(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		best;
	int		price_a;
	int		price_b;

	tmp = *b;
	best = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->price_a) + ft_abs(tmp->price_b) < ft_abs(best))
		{
			best = ft_abs(tmp->price_b) + ft_abs(tmp->price_a);
			price_a = tmp->price_a;
			price_b = tmp->price_b;
		}
		tmp = tmp->next;
	}
	make_move(a, b, price_a, price_b);
}
