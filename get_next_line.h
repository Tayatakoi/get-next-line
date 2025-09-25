/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:34:36 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/25 22:28:34 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
t_list	*create_and_add_node(t_list *list, char *content);
t_list	*find_newline_in_list(t_list *list, int *position);
t_list	*cleanup_list(t_list *list, t_list *newline_node, int position);
char	*extract_line(t_list *list, t_list *newline_node, int position);
int		read_and_build_list(int fd, t_list **list);

#endif