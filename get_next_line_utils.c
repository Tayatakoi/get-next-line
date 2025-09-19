/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/19 21:51:50 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int	lenght_of_string;
	char *s;
	
	lenght_of_string = 0;
	while (str[lenght_of_string])
		lenght_of_string++;
	s = malloc(sizeof(char)* lenght_of_string + 1);
	if (!s)
		return (NULL);
	lenght_of_string = 0;
	while (str[lenght_of_string])
	{
		s[lenght_of_string] = str[lenght_of_string];
		lenght_of_string++;
	}
	s[lenght_of_string] = '\0';
	return (s);
}

t_list	*creates_a_new_node(char *content)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    new_node->content = ft_strdup(content);
    new_node->next = NULL;
    return (new_node);
}
t_list	*adds_a_node_to_the_end(t_list *list, t_list *new_node)
{
	t_list *temp;

	temp = list;
    if (list == NULL)
        return (new_node);
    else
    {
        while (temp->next != NULL)
    		temp = temp->next;
        temp->next = new_node;
    }
    return (list);
}
t_list *find_newline_in_list(t_list *list, int *position)
{
    t_list *temp = list;
    int i;

    while (temp != NULL)
    {
        i = 0;
        while (temp->content[i])
        {
            if (temp->content[i] == '\n')
            {
                *position = i;
                return (temp);
            }
            i++;
        }
        temp = temp->next;
    }
    *position = -1;
    return (NULL);
}
char *extract_line_from_list(t_list *list, t_list *newline_node, int position)
{
	int total_length; // i need to count the legth till i find the node that has '\n' inside its content
	t_list *current;

	total_length = 0; //how do i count the legth?
	current = list;
	while (current != newline_node)
	{
		int node_length;
		
		node_length = 0;
		while(current->content[node_length])
			node_length++;
		current = current->next;
	}
}

