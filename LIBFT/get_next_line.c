/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:29:13 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/30 22:05:55 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

size_t	gl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	return (i);
}

char	*ft_strjoin1(char *str1, char *str2)
{
	char	*retn;
	size_t	i;

	retn = malloc(gl_strlen(str1) + gl_strlen(str2) + 1);
	if (!retn)
		return (NULL);
	i = 0;
	while (str1 && str1[i])
	{
		retn[i] = str1[i];
		i++;
	}
	free(str1);
	while (*str2)
	{
		retn[i++] = *str2;
		if (*str2++ == 10)
			break ;
	}
	retn[i] = 0;
	return (retn);
}

int	nl(char *buf)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	while (buf[i])
	{
		if (b == 1)
			buf[a++] = buf[i];
		if (buf[i] == 10)
			b = 1;
		buf[i++] = 0;
	}
	return (b);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*buff || read(fd, buff, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin1(line, buff);
		if (nl(buff) == 1)
			break ;
	}
	return (line);
}
