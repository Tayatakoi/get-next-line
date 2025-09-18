/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:07:40 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/18 23:29:59 by samamaev         ###   ########.fr       */
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
    new_node->content = content;
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
t_newline_pos find_newline_in_list(t_list *list)
{
	t_list	*temp;
	int	i;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		//we need to search for /n inside the node but how - idk, maybe we need to use strchr
		//by cheacking the content of the node
		while (temp->content[i])
		{
			i = 0;
			if (temp->content[i] == '\n')
			{
				t_newline_pos result; //what we are returning???
				result.node = temp;
				result.position = i;
				return (result);
			}
			i++;
		}
	}
}
