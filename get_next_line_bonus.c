/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 19:39:27 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/06 19:47:49 by albzamor         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

int	free_del(char **del, int re_turn)
{
	if (*del)
	{
		free(*del);
		*del = 0;
	}
	return (re_turn);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*sl[4096];
	char		*temp;
	long long	len;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1 )
	{
		return (-1);
	}
	if (fd)
		buf[0] = '\0';
	if (sl[fd] == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		sl[fd] = ft_strdup(buf);
	}
	while (!(ft_strchr(sl[fd], '\n')))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
		{
			buf[len] = '\0';
			temp = sl[fd];
			sl[fd] = ft_strjoin(sl[fd], buf);
			free(temp);
		}
		else if (len == 0)
		{
			*line = ft_substr(sl[fd], 0, ft_strlen(sl[fd]));
			free(sl[fd]);
			sl[fd] = NULL;
			return (0);
		}
		else if (len == -1)
			return (-1);
	}
	*line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n'));
	temp = sl[fd];
	sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
	free(temp);
	return (1);
}

/*

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
	read(fd, buf, BUFFER_SIZE);
	if (sl[fd] == NULL)
		sl[fd] = ft_strdup(buf);
	while (ft_strlen(sl[fd]) > 0
	{
		while (ft_strchr(sl[fd], '\n'))
		{
			*line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n'));
			sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
			return (1);
		}
		if (read(fd, buf, BUFFER_SIZE) > 0)
		{
			temp = sl[fd];
			sl[fd] = ft_strjoin(sl[fd], buf);
			free(temp);
		}
		else
			return (0);
	}
	return (0);
}

*/
