/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:40:12 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:57:12 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_with_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		ft_free_list(a);
	if (b == NULL || *b != NULL)
		ft_free_list(b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	ft_free_list(t_stack **a)
{
	t_stack	*tmp;

	if (a == NULL || *a == NULL)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}

void	ft_free(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}
