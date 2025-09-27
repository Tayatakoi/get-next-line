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

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
void	append_node(t_list **list, char *buffer);
t_list	*find_last_node(t_list *list);
int		found_newline(t_list *list);
char	*extract_line(t_list *list);
int		len_to_newline(t_list *list);
void	chistka(t_list **list, t_list *clean_node, char *buf);
void	copy_content_to_line(char *next_str, t_list *list, int *k);
void	create_list(t_list **list, int fd);
void	polish_list(t_list **list);
char	*get_next_line(int fd);

#endif
