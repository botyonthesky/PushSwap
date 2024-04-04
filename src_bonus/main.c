/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:03:36 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/19 16:31:37 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	checker(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (is_valid_command(str) == 1)
		{
			free(str);
			free_s(a);
			free_s(b);
			ft_putendl_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		check_command(a, b, str);
		if (str)
			free(str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (check_split_argv(&a, argc, argv) == 1)
		return (1);
	if (checker(&a, &b))
	{
		if (!(b) && is_sorted(&a))
			ft_putendl_fd("OK", STDOUT_FILENO);
		else
			ft_putendl_fd("KO", STDOUT_FILENO);
	}
	free_s(&a);
	free_s(&b);
	return (0);
}
