/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_addb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:11:32 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:11:35 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_gc_addb(t_gc **lst, t_gc *new)
{
	t_gc	*lstlast;

	if (*lst == NULL)
		*lst = new;
	else
	{
		lstlast = ft_gc_last(*lst);
		lstlast->next = new;
	}
}
