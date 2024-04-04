/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:13:18 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:17:33 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*add_to(int argc, char **argv)
{
	t_stack		*a;
	long int	nb;
	int			i;

	a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoli(argv[i]);
		if (check_min_max(nb) == 1)
			exit_with_error(&a, NULL);
		if (i == 1)
			a = add_front((int)nb);
		else
			fill_by_end(&a, add_front((int)nb));
		i++;
	}
	return (a);
}

t_stack	*add_front(long nb)
{
	t_stack	*result;

	result = malloc(sizeof * result);
	if (result == NULL)
		return (NULL);
	result->value = nb;
	result->i = 0;
	result->pos = -1;
	result->goal_pos = -1;
	result->price_a = -1;
	result->price_b = -1;
	result->next = NULL;
	return (result);
}

void	add_to_until_last_three(t_stack **a, t_stack **b)
{
	int	size;
	int	is_push;
	int	idx;

	size = stack_size(*a);
	is_push = 0;
	idx = 0;
	while (size > 6 && idx < size && is_push < size / 2)
	{
		if ((*a)->i <= size / 2)
		{
			exe_pb(a, b);
			is_push++;
		}
		else
			exe_ra(a);
		idx++;
	}
	while (size - is_push > 3)
	{
		exe_pb(a, b);
		is_push++;
	}
}
