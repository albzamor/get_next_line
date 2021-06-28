/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 12:35:02 by albzamor          #+#    #+#             */
/*   Updated: 2021/06/28 16:34:37 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line(int fd, char **line)
{
	static char	*s[4096];
	char		*buf;
	char		*ptr;

	// fd el id que nos da el open que haremos en el main
	if (fd < 0 || line == NULL)
		return (-1);
	if (!s || ptr == NULL)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)

	while ((read(fd, buf, BUFFER_SIZE)) > 0)
	{
		line
	}

}


ft_strdup(buff)



int	main(int argc, char **argv)
{
	int	fd;
	char *line;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);

}






/* get_next_line
Write a function that will store, in the parameter “line”, a line that has been read from the given file descriptor.

Requirements
Your function must be prototyped as follows: int get_next_line(int fd, char **line);
Your function should be memory leak free.
What we call a “line that has been read” is a succession of 0 to n characters that end with ‘\n’ (ascii code 0x0a) or with End Of File (EOF).
The string stored in the parameter “line” should not contained any ‘\n’.
The parameter is the address of a pointer to a character that will be used to store the line read.
Return values
The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed (meaning read has returned 0), or if an error has happened respectively.

When you’ve reached the End Of File, you must store the current buffer in “line”. If the buffer is empty you must store an empty string in “line”.
When you’ve reached the End Of File, your function should keep 0 memory allocated with malloc except the last buffer that you should have stored in “line”.
What you’ve stored in “line” should be free-able.
Final words
Calling your function get_next_line in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines. Therfore, make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc. For the mandatory part, no call to another function will be done on the file descriptor between 2 calls of get_next_line.

Finally we consider that get_next_line has an undefined behavior when reading from a binary file. You may make this work accordingly, but its not part of the bonus nor is it required.

Testing
You can use my tester to help you test your program. */
