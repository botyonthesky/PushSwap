/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:11:42 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:13:00 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	make_move(t_stack **a, t_stack **b, int p_a, int p_b)
{
	if (p_a < 0 && p_b < 0)
		rev_rotate_for_ab(a, b, &p_a, &p_b);
	else if (p_a > 0 && p_b > 0)
		rotate_for_ab(a, b, &p_a, &p_b);
	rotate_a(a, &p_a);
	rotate_b(b, &p_b);
	exe_pa(a, b);
}

void	rev_rotate_for_ab(t_stack **a, t_stack **b, int *p_a, int *p_b)
{
	while (*p_a < 0 && *p_b < 0)
	{
		(*p_a)++;
		(*p_b)++;
		exe_rrr(a, b);
	}
}

void	rotate_for_ab(t_stack **a, t_stack **b, int *p_a, int *p_b)
{
	while (*p_a > 0 && *p_b > 0)
	{
		(*p_a)--;
		(*p_b)--;
		exe_rr(a, b);
	}
}
