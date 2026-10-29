/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:12:30 by mabuhila          #+#    #+#             */
/*   Updated: 2026/10/29 17:49:58 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s2)
		return (freebuff(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1);
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) & s[i]);
	return (NULL);
}
