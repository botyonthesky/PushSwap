/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 06:50:46 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 06:52:06 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		a_size;

	if (argc < 2)
		return (0);
	if (!check_argv(argv))
	{
		exit_with_error(NULL, NULL);
	}
	b = NULL;
	a = add_to(argc, argv);
	a_size = stack_size(a);
	define_idx(a, a_size + 1);
	exe_ps_cmd(&a, &b, a_size);
	ft_free_list(&a);
	ft_free_list(&b);
	return (0);
}
