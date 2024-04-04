/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:11:44 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:11:46 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_memcheck(t_gc **ptrs, void *p, int side, int is_fd)
{
	t_gc	*lstnew;

	lstnew = ft_gc_new(p);
	if (lstnew == NULL)
	{
		ft_gc_clear(ptrs);
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
	lstnew->fd = is_fd;
	if (side == BACK)
		ft_gc_addb(ptrs, lstnew);
	else
		ft_gc_addf(ptrs, lstnew);
	if (is_fd == MEM && p == NULL)
	{
		ft_gc_clear(ptrs);
		perror("Memory allocation failed");
		exit (EXIT_FAILURE);
	}
}
