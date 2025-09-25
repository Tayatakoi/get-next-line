/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samamaev <samamaev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:33:36 by samamaev          #+#    #+#             */
/*   Updated: 2025/09/25 20:42:31 by samamaev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_clean(t_list **stored, t_list *newline_node, int position)
{
	char	*line;

	line = extract_line(*stored, newline_node, position);
	*stored = cleanup_list(*stored, newline_node, position);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*stored = NULL;
	t_list			*newline_node;
	int				read_result;
	int				position;

	if (fd < 0)
		return (NULL);
	newline_node = find_newline_in_list(stored, &position);
	if (newline_node)
		return (extract_clean(&stored, newline_node, position));
	read_result = read_and_build_list(fd, &stored);
	if (read_result <= 0)
		return (NULL);
	newline_node = find_newline_in_list(stored, &position);
	if (newline_node)
		return (extract_clean(&stored, newline_node, position));
	return (NULL);
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
