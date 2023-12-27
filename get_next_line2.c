/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:12:13 by livliege          #+#    #+#             */
/*   Updated: 2023/12/22 21:17:29 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// #include "get_next_line.h"

// // take these out:
// #include <stdio.h>
// // did you take out the forbidden headers?

// #define RED "\033[91m"
// #define GREEN "\033[92m"
// #define BLUE "\033[94m"
// #define DEFAULT "\033[0m"

// # define FD_LIMIT 1024

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif

// char	*readline(int fd, char *buffer)
// {
// 	static char *substrings[FD_LIMIT];
// 	char *line;
// 	char *temp;
// 	int bytes_read;
// 	int i;
// 	int j;
// 	int nlc;
	
// 	bytes_read = 1;
	
// 	line = NULL;
// 	substrings[fd] = NULL;
// 	// First we check if substrings has anything in it, and if so we join the (empty) line with whatever was left in substrings
// 	if (substrings[fd] != NULL)
// 	{
// 		line = ft_strjoin(line, substrings[fd]);
// 		substrings[fd] = NULL;
// 	}
// 	// Then we start reading the fd, and put it in buffer, which we give a '\0'.
// 	while (bytes_read != 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		// if (bytes_read < 0)
// 		buffer[bytes_read] = '\0';
// 	// If we find a new line character in buffer, we have to slit this string into the part that we want to put in line, and the part that belongs to the next line
// 		if (ft_strchr(buffer, '\n'))
// 		{
// 			i = 0;
// 			nlc = 0;
// 	// We fist need to know where the new line character is.
// 			while (buffer[nlc] != '\n')
// 				nlc++;
// 	// Now we need to copy everything into a temp string, INCLUDING the nlc (next line character)
// 			temp = (char *)malloc(sizeof (char) * BUFFER_SIZE + 1);
// 			while (i <= nlc)		// can I do this? : 	while (nlc > i++) 
// 			{
// 				temp[i] = buffer[i];
// 				i++;
// 			}
// 			temp[i] = '\0';
// 			line = ft_strjoin(line, temp);
// 	// Now we can join our line with the last bit of the new line (whatever was in buffer before the nlc)
// 			j = 0;
// 	// i = nlc + 1, so the index is now one after nlc, so we can start copying the rest of the buffer into substrings[fd]
// 	// side note: we only start usinf j here, so we can also set nlc to 0 to safe function lines and memory (4 whole bytes!!)
// 			while (buffer[i] != '\0')
// 			{
// 				substrings[fd][j] = buffer[i];
// 				j++;
// 				i++;
// 			}
// 		}
// 		else
// 			line = ft_strjoin(line, buffer);
// 	}
// 	// free line?
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	char *buffer;
// 	char *next_line;
	
// 	buffer = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
// 	next_line = readline(fd, buffer);
// 	// free(buffer);
// 	return (next_line);
// }

// int	main(void)
// {
// 	int fd1;
// 	int fd2;
// 	// int fd3;

// 	fd1 = open("textfile1.txt", O_RDONLY);
// 	fd2 = open("textfile2.txt", O_RDONLY);
// 	// fd3 = open("textfile3.txt", O_RDONLY);

// 	printf("The fist 	line of the file 1 = %s\n", get_next_line(fd1));
// 	printf("The fist 	line of the file 2 = %s\n", get_next_line(fd2));
// 	// printf("The fist 	line of the file 3 = %s\n", get_next_line(fd3));
// 	printf("The seccond line of the file 1 = %s\n", get_next_line(fd1));
// 	printf("The seccond line of the file 2 = %s\n", get_next_line(fd2));
// 	// printf("The seccond line of the file 3 = %s\n", get_next_line(fd3));

// 	return (0);
// }




#include "get_next_line.h"

// take these out:
#include <stdio.h>
// did you take out the forbidden headers?

#define RED "\033[91m"
#define GREEN "\033[92m"
#define BLUE "\033[94m"
#define DEFAULT "\033[0m"

# define FD_LIMIT 1024



char *get_remainder(char *line)
{
	int i;
	int j;
	char *remainder;
	
	i = 0;
	remainder = (char *)malloc(sizeof(char) * ft_strlen(line));
	if (remainder == NULL)
		return (NULL); 
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i] != '\0')
	{
		remainder[j] = line[i];
		i++;
		j++;
	}
	remainder[j] = '\0';
	return (remainder);
}
char *get_line(char *line)
{
	int i;
	char *next_line;
	
	// printf("'%s%s%s',\n", RED, line, DEFAULT);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * (i + 2));
	if (next_line == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		next_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		next_line[i] = line[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char *read_to_nlc(int fd, char *line)
{
	int bytes_read;
	char *buffer;
	char *tmp;
	
	// printf("'%s%s%s',\n", RED, line, DEFAULT);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1); // protect this
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE); // if bytes < 0, protect this
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
	}
	free (buffer);
	printf("%s%s%s\n", RED, line, DEFAULT);
	return (line);
}

// char *dorian_read_to_nlc(int fd, char *line)
// {
// 	int		bytes_read;
// 	char	*buffer;
// 	char	*tmp;
// 	int		strlen;

// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (buffer == NULL)
// 		return (NULL);
// 	bytes_read = 1;
// 	while (!ft_strchr(line, '\n') && bytes_read != 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE); // if bytes < 0, protect this
// 		if (bytes_read < 0)
// 			return (free(buffer), NULL);
// 		buffer[bytes_read] = '\0';
// 		tmp = ft_strjoin(line, buffer);
// 		free(line);
// 		line = tmp;
// 	}
// 	free (buffer);
// 	// printf("%s%s%s\n", RED, line, DEFAULT);
// 	return (line);
// }

char *get_next_line(int fd)
{
	static char *substrings[FD_LIMIT];
	char *next_line;
	char *temp;	// do I need to give it a size?

	// if (fd <= 0 || BUFFER_SIZE == 0 || BUFFER_SIZE > INT_MAX)
	// 	return (NULL);
	if (!substrings[fd] || !ft_strchr(substrings[fd], '\n'))
		substrings[fd] = read_to_nlc(fd, substrings[fd]);
	next_line = get_line(substrings[fd]);
	temp = get_remainder(substrings[fd]);
	free (substrings[fd]);
	substrings[fd] = temp;
	return (next_line);
}


// int	main(void)
// {
// 	int fd1;
// 	int fd2;
// 	// int fd3;

// 	fd1 = open("textfile.txt", O_RDONLY);
// 	fd2 = open("textfile2.txt", O_RDONLY);
// 	// fd3 = open("textfile3.txt", O_RDONLY);
	
// 	printf("The fist 	line of the file 1 = %s\n", get_next_line(fd1));
// 	printf("The fist 	line of the file 2 = %s\n", get_next_line(fd2));
// 	// printf("The fist 	line of the file 3 = %s\n", get_next_line(fd3));
// 	printf("The seccond line of the file 1 = %s\n", get_next_line(fd1));
// 	printf("The seccond line of the file 2 = %s\n", get_next_line(fd2));
// 	// printf("The seccond line of the file 3 = %s\n", get_next_line(fd3));

// 	return (0);
// }


int	main(void)
{
	int fd1;
	// int fd2;
	// int fd3;
	int nb;
	char *line;

	fd1 = open("textfile1.txt", O_RDONLY);
	// fd2 = open("textfile2.txt", O_RDONLY);
	// fd3 = open("textfile3.txt", O_RDONLY);

	nb = 1;
	while (nb <= 10)
	{
		line = get_next_line(fd1);
		printf("line %d of fd1 is: %s", nb, line);
		free(line);
		// line = get_next_line(fd2);
		// printf("line %d of fd2 is: %s\n", nb, line);
		// free(line);
		// line = get_next_line(fd3);
		// printf("line %d of fd3 is: %s\n", nb, line);
		// free(line);
		nb++;
	}
	// close fd's?
	return (0);
}









// --------------------------------------------------------

// #include "get_next_line.h"

// // take these out:
// #include <stdio.h>
// // did you take out the forbidden headers?

// #define RED "\033[91m"
// #define GREEN "\033[92m"
// #define BLUE "\033[94m"
// #define DEFAULT "\033[0m"

// # define FD_LIMIT 1024

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif



// char	*new_line(int fd, char *static_buffer)
// {
// 	char	*buffer;
// 	int		size;

// 	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	size = 1;
// 	while (!ft_strchr(static_buffer, '\n') && size != 0)
// 	{
// 		size = read(fd, buffer, BUFFER_SIZE);
// 		if (size == -1)
// 		{
// 			free(static_buffer);
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[size] = '\0';
// 		static_buffer = ft_strjoin(static_buffer, buffer);
// 	}
// 	free(buffer);
// 	return (static_buffer);
// }

// char	*fixed_line(char *static_buffer)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!static_buffer[i])
// 		return (NULL);
// 	while (static_buffer[i] && static_buffer[i] != '\n')
// 		i++;
// 	line = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (static_buffer[i] && static_buffer[i] != '\n')
// 	{
// 		line[i] = static_buffer[i];
// 		i++;
// 	}
// 	if (static_buffer[i] == '\n')
// 	{
// 		line[i] = static_buffer[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// char	*next_line(char *static_buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*tab;

// 	i = 0;
// 	while (static_buffer[i] && static_buffer[i] != '\n')
// 		i++;
// 	if (!static_buffer[i])
// 	{
// 		free(static_buffer);
// 		return (NULL);
// 	}
// 	tab = (char *)malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
// 	if (!tab)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (static_buffer[i])
// 		tab[j++] = static_buffer[i++];
// 	tab[j] = '\0';
// 	free(static_buffer);
// 	return (tab);
// }

// char	*get_next_line(int fd)
// {
// 	char		*ln;
// 	static char	*static_buffer[10240];

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (0);
// 	static_buffer[fd] = new_line(fd, static_buffer[fd]);
// 	if (!static_buffer[fd])
// 		return (NULL);
// 	ln = fixed_line(static_buffer[fd]);
// 	static_buffer[fd] = next_line(static_buffer[fd]);
// 	return (ln);
// }


