/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/07 19:40:39 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *find_or_create_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*new_node;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->buffer = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
int reading(t_list *node,int fd)
{
	char	temp_buf[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*new_buffer;
	while (!ft_strchr(node->buffer, '\n'))
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
			return (0);
		temp_buf[bytes_read] = '\0';
		new_buffer = ft_strjoin(node->buffer, temp_buf);
		if (!new_buffer)
			return (-1);
		free(node->buffer);
		node->buffer = new_buffer;
	}
}
