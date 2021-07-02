/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/07/02 13:00:40 by albzamor         ###   ########.fr       */
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
	char		buf[BUFFER_SIZE];
	static char	*static_line[4096];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	static_line[fd] = malloc(0);
	while ((read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			static_line[fd] = ft_strjoin(static_line[fd], buf);
			*line = ft_substr(static_line[fd], 0, ft_strchr2(static_line[fd], '\n'));
			static_line[fd] = ft_substr(static_line[fd], ft_strchr2(static_line[fd], '\n'), ft_strlen(static_line[fd]));
			return (1);
		}
		else
		{
			temp = static_line[fd];
			static_line[fd] = ft_strjoin(static_line[fd], buf);
			free(temp);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("\033[0;31mprimera linea: 🚀 \033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31msegunda linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31mtercera linea: 🚀\033[0;37m%s", line);
	printf("\n");
	//system("leaks a.out");
}
