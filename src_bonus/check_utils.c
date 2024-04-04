/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:53:00 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/19 17:36:09 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

long int	ft_atoli(const char *nptr)
{
	int			i;
	long int	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_sorted(t_stack **x)
{
	t_stack	*tmp;
	int		last;

	if (!*x)
	{
		ft_putendl_fd("Error", STDOUT_FILENO);
		exit (1);
	}
	tmp = *x;
	last = tmp->value;
	while (tmp)
	{
		if (tmp->value < last)
			return (0);
		last = tmp->value;
		tmp = tmp->next;
	}
	return (free_s(x), 1);
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

int	check_min_max(long int n)
{
	if (n < INT_MIN || n > INT_MAX)
		return (1);
	return (0);
}
