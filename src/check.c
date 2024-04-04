/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:53:55 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:56:15 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_argv(char **argv)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (0);
		zero += is_zero(argv[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (check_for_identical(argv))
		return (0);
	return (1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && is_digit(str[i]))
		i++;
	if (str[i] != '\0' && !is_digit(str[i]))
		return (0);
	return (1);
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}
