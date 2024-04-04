/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:06:47 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/19 17:34:46 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	load_stack(t_stack **a, char **argv, int x)
{
	int			i;
	long int	nb;
	t_stack		*new;

	if (x == 1)
		i = 0;
	else
		i = 1;
	nb = 0;
	while (argv[i])
	{
		nb = ft_atoli(argv[i]);
		if (check_min_max(nb) == 1)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			free_s(a);
			exit (1);
		}
		new = stack_new(nb);
		stack_back(a, new);
		i++;
	}
	return (0);
}

void	stack_back(t_stack **x, t_stack *new)
{
	t_stack	*tmp;

	tmp = *x;
	if (tmp == NULL)
	{
		*x = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_stack	*stack_new(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->value = n;
	new->next = NULL;
	return (new);
}

void	free_s(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while ((*stack) != NULL)
		{
			tmp = *stack;
			(*stack) = (*stack)->next;
			free(tmp);
		}
	}
}
