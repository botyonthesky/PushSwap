/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:56:49 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/10 18:00:31 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	check_command(t_stack **a, t_stack **b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		check_swap(a);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		check_swap(b);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		check_ss(a, b);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		check_pa(a, b);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		check_pb(a, b);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		check_ra(a);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		check_rb(b);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		check_rr(a, b);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		check_rra(a);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		check_rrb(b);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		check_rrr(a, b);
}

int	is_valid_command(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		return (0);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		return (0);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (0);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (0);
	return (1);
}
