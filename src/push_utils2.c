/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:59:30 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:55:56 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	check_for_identical(char **argv)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 1;
	while (argv[i])
	{
		x = ft_atoi(argv[i]);
		j = 1;
		while (argv[j])
		{
			y = ft_atoi(argv[j]);
			if (i != j && x == y)
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	check_min_max(long int n)
{
	if (n < INT_MIN || n > INT_MAX)
		return (1);
	return (0);
}

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
