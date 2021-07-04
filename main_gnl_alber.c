
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	//while (get_next_line(fd, &line) != 0)
		//printf("\033[0;31mprimera linea: 🚀\033[0;37m%s\n", line);
	get_next_line(fd, &line);
	printf("\033[0;31mprimera linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31msegunda linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31mtercera linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31mcuarta  linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31mquinta  linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31msexta   linea: 🚀\033[0;37m%s", line);
	printf("\n");
	get_next_line(fd, &line);
	printf("\033[0;31mseptia  linea: 🚀\033[0;37m%s", line);
	printf("\n");
	//system("leaks a.out");
}
