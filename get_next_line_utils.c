/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/05 22:14:38 by samamaev         ###   ########.fr       */
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