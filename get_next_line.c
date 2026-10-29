/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:18:05 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/29 18:00:17 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freebuff(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	int		i;
	int		j;

	if (!remainder)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
		return (freebuff(remainder));
	new_remainder = malloc(ft_strlen(remainder + i + 1) + 1);
	if (!new_remainder)
	{
		free(remainder);
		return (NULL);
	}
	i++;
	j = 0;
	while (remainder[i])
		new_remainder[j++] = remainder[i++];
	new_remainder[j] = '\0';
	free(remainder);
	return (new_remainder);
}

char	*extract_line(char *remainder)
{
	char	*line;
	size_t	len;

	if (!remainder || !remainder[0])
		return (NULL);
	len = 0;
	while (remainder[len] && remainder[len] != '\n')
		len++;
	if (remainder[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, remainder, len);
	line[len] = '\0';
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
	while (rbytes > 0)
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
		if (ft_strchr(buffer, '\n'))
			break ;
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
	if (!line)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	remainder = update_remainder(remainder);
	return (line);
}
