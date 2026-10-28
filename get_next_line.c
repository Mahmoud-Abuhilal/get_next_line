/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:18:05 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/28 17:38:30 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freebuff(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*extract_line(char *remainder)
{
	char	*line;
	int		i;

	if (!remainder || !remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = malloc(i + (remainder[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i])
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_remainder(int fd, char *remainder)
{
	char	*buffer;
	int		rbytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (freebuff(remainder));
	rbytes = 1;
	while (rbytes > 0 && (!ft_strchr(remainder, '\n')))
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(remainder);
			free(buffer);
			return (NULL);
		}
		buffer[rbytes] = '\0';
		remainder = ft_strjoin_free(remainder, buffer);
		if (!remainder)
			return (freebuff(buffer));
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = extract_line(remainder);
}
