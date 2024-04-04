/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:17:50 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/19 16:36:24 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/gnl.h"

void	*ft_free_node(t_buf **head_node)
{
	t_buf	*current_node;

	current_node = *head_node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
		free((*head_node)->buf);
		(*head_node)->buf = NULL;
		free(*head_node);
		*head_node = current_node;
	}
	return (NULL);
}

void	*ft_free_buf(char	**buf)
{
	free(*buf);
	*buf = NULL;
	return (NULL);
}

void	*ft_align_buf_to_node(t_buf **head_node, size_t start, size_t end)
{
	char	*buf;
	t_buf	*current_node;
	size_t	i;

	buf = malloc(end - start + 1);
	if (buf == NULL)
		return (NULL);
	current_node = *head_node;
	i = 0;
	while (current_node->buf[start] != '\0')
	{
		buf[i] = current_node->buf[start];
		start++;
		i++;
	}
	buf[i] = '\0';
	free(current_node->buf);
	current_node->buf = buf;
	return (NULL);
}

void	*ft_align_line_node(t_buf	**head_node)
{
	t_buf	*current_node;
	size_t	start;
	size_t	end;

	current_node = *head_node;
	start = 0;
	while (current_node->buf[start] != '\n' && current_node->buf[start] != '\0')
		start++;
	if (current_node->buf[start] == '\n')
		start++;
	end = start;
	while (current_node->buf[end] != '\0')
		end++;
	if (end == start)
	{
		free((*head_node)->buf);
		(*head_node)->buf = NULL;
		free(*head_node);
		*head_node = NULL;
		return (NULL);
	}
	return (ft_align_buf_to_node(&current_node, start, end));
}
