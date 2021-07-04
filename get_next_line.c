/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/04 17:21:02 by albzamor         ###   ########.fr       */
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

int	free_del(char **del, int ret)
{
	if (*del)
	{
		free(*del);
		*del = 0;
	}
	return (ret);

}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*sl[4096];
	char		*temp;
	long long 	len;


	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf[BUFFER_SIZE] = '\0';
	if (sl[fd] == NULL)
	{
		read(fd, buf, BUFFER_SIZE);
		sl[fd] = ft_strdup(buf);
	}
	while (!(ft_strchr(sl[fd], '\n')))
	{
		if((len = read(fd, buf, BUFFER_SIZE)) > 0) //OJO
		{
			buf[len] = '\0';
			temp = sl[fd];
			sl[fd] = ft_strjoin(sl[fd], buf);
			free(temp);
		}
		else if (len == 0)
		{
			temp = sl[fd];
			*line = ft_substr(sl[fd], 0, ft_strlen(sl[fd]));
			free(temp);
			//if (*(sl[fd]))
				//free(sl[fd]);
			return (0);
		}
		else if (len == -1)
			return (-1);
	}
	temp = sl[fd];
	*line = ft_substr(sl[fd], 0, ft_strchr2(sl[fd], '\n'));
	free(temp);
	sl[fd] = ft_substr(sl[fd], ft_strchr2(sl[fd], '\n') + 1, ft_strlen(sl[fd]));
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
