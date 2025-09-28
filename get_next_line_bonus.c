/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:43:16 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/28 23:19:59 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	chistka(list, clean_node, buf);
}

int	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!find_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (0);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			return (-1);
		}
		if (char_read == 0)
		{
			free(buf);
			return (0);
		}
		buf[char_read] = '\0';
		append_node(list, buf);
	}
	return (1);
}

char	*extract_line(t_list *list)
{
	int		str_len;
	char	*next_str;
	int		k;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	k = 0;
	while (list)
	{
		copy_content(next_str, list, &k);
		if (k > 0 && next_str[k - 1] == '\n')
		{
			next_str[k] = '\0';
			return (next_str);
		}
		list = list->next;
	}
	next_str[k] = '\0';
	return (next_str);
}

void	append_node(t_list **list, char *buffer)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->content = buffer;
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last_node = find_last_node(*list);
		last_node->next = new_node;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list[MAX_FD] = {NULL};
	char			*next_line;
	int				result;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	result = create_list(&list[fd], fd);
	if (result == -1)
	{
		chistka(&list[fd], NULL, NULL);
		return (NULL);
	}
	if (!list[fd])
		return (NULL);
	next_line = extract_line(list[fd]);
	polish_list(&list[fd]);
	return (next_line);
}

// #include <unistd.h>
// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *test;
// 	test = get_next_line(fd);
// 	while (test)
// 	{
// 		printf("%s", test);
// 		test = get_next_line(fd);	
// 	}
// 	return (0);
// }