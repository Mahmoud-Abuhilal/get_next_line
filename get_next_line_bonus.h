/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuhila <mabuhila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:51:35 by mabuhila          #+#    #+#             */
/*   Updated: 2026/11/02 15:11:07 by mabuhila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*freebuff(char *buffer);

#endif
