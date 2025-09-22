/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/21 21:49:51 by samamaev         ###   ########.fr       */
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
t_list *create_and_add_node(t_list *list, char *content)
{
    t_list *new_node;
    t_list *temp;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (list);  // Return original list if malloc fails
    new_node->content = ft_strdup(content);
    if (!new_node->content)
    {
        free(new_node);
        return (list);
    }
    new_node->next = NULL;
    if (list == NULL)
        return (new_node);
    temp = list;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return (list);
}
t_list *find_newline_in_list(t_list *list, int *position)
{
    t_list *temp = list;//so, we can manipulate the list without changing it
    int i;

    while (temp != NULL)
    {
        i = 0;
        while (temp->content[i])
        {
            if (temp->content[i] == '\n') // cool, right?
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
    char *m;
    int node_length;
    int i;
    int j;

	total_length = 0; //how do i count the legth?
	current = list;
	while (current != newline_node)
	{
		node_length = 0;
		while(current->content[node_length])
			node_length++;
        total_length += node_length;
		current = current->next;
	}
    total_length += position + 1; //so, this is for the node that actually has '\n' inside the content
    m = malloc(sizeof(char)* total_length + 1); //dont forget to enclude '\n'
    if (!m)
        return (NULL);
    node_length = 0;
    current = list;
    i = 0;
    j = 0;
    while (current != newline_node)
    {
        while (current->content[node_length])
            m[i++] = current->content[node_length++];
        current = current->next;
        node_length = 0;
    }
    j = 0;
    while (j <= position)
        m[i++] = current->content[j++];
    m[i] = '\0';
    return (m);
}
t_list *cleanup_list_after_extraction(t_list *list, t_list *newline_node, int position)
{
    char *leftover;

    
    
}
