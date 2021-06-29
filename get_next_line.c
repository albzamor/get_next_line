/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/06/29 19:58:32 by albzamor         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	i = 0;
	while (s1[i] != '\0')
		i++;
	copy = ft_calloc(i + 1, sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*static_line[4096];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ft_strchr(buf, '\n'))
		{
			static_line[fd] = malloc (ft_strlen(buf));
			static_line[fd] = ft_strjoin(static_line[fd], buf);
			*line = *ft_split(static_line[fd], '\n');
			return (1);
		}
		//if (!static_line[fd])
			//static_line[fd] = ft_strdup(buf);
		//else
			//ft_strjoin(static_line[fd], buf);
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
	printf("primera linea: %s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("segunda linea: %s", line);
	printf("\n");
}
