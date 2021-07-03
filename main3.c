#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int a;
	int i = 10;
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while (i-- > 0)
	{
		a = get_next_line(fd, &line);
		printf("\033[0;31mprimera linea: 🚀\033[0;37m%s\n", line);
		printf("%d", a);
	}
	/* get_next_line(fd, &line);
	printf("\033[0;31mprimera linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31msegunda linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31mtercera linea: 🚀\033[0;37m%s", line);
	printf("\n"); */
	//system("leaks a.out");
}
