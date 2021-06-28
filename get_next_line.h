/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:34:07 by albzamor          #+#    #+#             */
/*   Updated: 2021/06/25 12:34:07 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>








#endif




















int		get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*x[4096];
	ssize_t		nbytes;
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
		(!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((nbytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nbytes] = '\0';
		if (!x[fd])
			x[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(x[fd], buff);
			free(x[fd]);
			x[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (ft_aux(nbytes, &x[fd], &*line));
}