/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:18:05 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/26 17:27:19 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line_size(int fd)
{
	int		count;
	char	*buffer;

	count = 0;
	count += read(fd, &c, 1);
	if (count <= 0)
		return (0);
	while (*buffer)
	{
		if (read(fd, &c, 1) > 0)
			count++;
		if (c == '\n')
			return (count);
	}
	return (count);
}

char	*get_next_line(int fd)
{
	int		i;
	char	*line;

	if (fd < 0)
		return (NULL);
	i = get_line_size(fd);
	if (i == 0)
		return (NULL);
	line = malloc(i);
	if (!line)
		return (NULL);
	read(fd, line, i);
	return (line);
}
