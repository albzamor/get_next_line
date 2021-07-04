/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:42:37 by adorigo           #+#    #+#             */
/*   Updated: 2019/12/05 11:54:23 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	ft_putendl(char const *s)
{
	int i;

	i = ft_strlen(s);
	if (s)
		write(1, s, i);
	write(1, "\n", 1);
}


int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	ft_putendl(line);
	free(line);
	if (argc == 2)
		close(fd);
}