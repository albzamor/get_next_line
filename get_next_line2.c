/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/03 14:10:29 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_strchr2(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (pos);
		s++;
		pos++;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*sl[4096];
	char		*temp;

	buf[BUFFER_SIZE] = '\0';
	if (fd < 0 || line == NULL)
		return (-1);
	if (sl[fd] == NULL)
		sl[fd] = ft_strdup("");
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		sl[fd] = ft_strjoin(sl[fd], buf);
		if (ft_strchr(sl[fd], '\n'))
			break;
		else
		{
			temp = sl[fd];
			sl[fd] = ft_strjoin(sl[fd], buf);
			free(temp);
		}
	}
	if (ft_strlen(sl[fd]) < 1)
		return (0);
	*line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n'));
	sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
	return (1);
	// if (read(fd, buf, BUFFER_SIZE) == -1)
	// 	return (-1);
	// return (0);
}
