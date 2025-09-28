/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:43:07 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/28 23:10:25 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define MAX_FD 1024

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
void	append_node(t_list **list, char *buffer);
t_list	*find_last_node(t_list *list);
int		find_newline(t_list *list);
char	*extract_line(t_list *list);
int		len_to_newline(t_list *list);
void	chistka(t_list **list, t_list *clean_node, char *buf);
void	copy_content(char *next_str, t_list *list, int *k);
int		create_list(t_list **list, int fd);
void	polish_list(t_list **list);
char	*get_next_line(int fd);

#endif
