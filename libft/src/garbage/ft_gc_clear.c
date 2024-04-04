/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:11:18 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:11:19 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_gc_clear(t_gc **lst)
{
	t_gc	*ptr;
	t_gc	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		if (ptr->content != NULL && ptr->fd == 0)
		{
			free(ptr->content);
			ptr->content = NULL;
		}
		if (ptr->content != NULL && ptr->fd == 1)
		{
			if (*(int *)ptr->content != -1)
				close(*(int *)ptr->content);
		}
		free(ptr);
		ptr = NULL;
		ptr = next;
	}
	*lst = NULL;
}
