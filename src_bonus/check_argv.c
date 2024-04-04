/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:00:45 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/20 07:52:27 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	check_split_argv(t_stack **a, int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_and_load(a, argv, 1) == 1)
			return (1);
	}
	else if (argc > 2)
	{
		if (check_and_load(a, argv, 2) == 1)
			return (1);
	}
	if (is_duplicate(a) == 1)
	{
		free_s(a);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	check_and_load(t_stack **a, char **argv, int x)
{
	char	**args;

	args = NULL;
	if (x == 1)
	{
		args = ft_split(argv[1], ' ');
		if (is_valid_argv(args, 1) == 1)
		{
			ft_free(args);
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
		load_stack(a, args, 1);
		ft_free(args);
	}
	else
	{
		if (is_valid_argv(argv, 2) == 1)
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (1);
		}
		load_stack(a, argv, 2);
	}
	return (0);
}

int	is_duplicate(t_stack **a)
{
	t_stack	*current;
	t_stack	*runner;

	current = *a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_argv(char **args, int x)
{
	int	i;
	int	j;

	if (x == 1)
		i = 0;
	else
		i = 1;
	if (args[i] == NULL)
		return (1);
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] == '-' && j != 0)
				|| (args[i][j] == '-' && !args[i][j + 1]))
				return (1);
			if ((args[i][j] < '0' || args[i][j] > '9') && (args[i][j] != '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
