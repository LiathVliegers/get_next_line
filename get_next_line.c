/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2023/12/20 16:06:00 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define BLUE "\033[94m"
#define DEFAULT "\033[0m"

// TODO: check if all mallocs are freed correctly

char *get_remainder(char *line_nlc_remainder)
{
	char 	*remainder;
	char	*temp;
	int		nlc;
	int		i;

	if (line_nlc_remainder[i] == '\0')
		return (NULL);

	nlc = 0;
	while (line_nlc_remainder[nlc] != '\0' && line_nlc_remainder[nlc] != '\n')
		nlc++;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(line_nlc_remainder) - nlc + 1));
	if (temp == NULL)
		return (NULL);
	
	nlc++;

	i = 0;

	while (line_nlc_remainder != '\0')
		temp[i++] = line_nlc_remainder[nlc++];

	temp[i] = '\0';

	remainder = temp;  // use copy function?
	free (temp);
	return (remainder);
}


char *get_line(char *line_nlc_remainder)
{
	char 	*line;
	char	*temp;
	int		i;
	int		nlc;

	if (line_nlc_remainder[i] == '\0')
	{}
		return (NULL);

	nlc = 0;
	while (line_nlc_remainder[nlc] != '\0' && line_nlc_remainder[nlc] != '\n')
		nlc++;

	temp = (char *)malloc(sizeof(char) * (nlc + 2));
	if (temp == NULL)
		return (NULL);

	i = 0;
	while (line_nlc_remainder[i] != '\0' && line_nlc_remainder[i] != '\n')
	{
		temp[i] = line_nlc_remainder[i];
		i++;
	}
	if (line_nlc_remainder[i] == '\n')
	{
		temp[i] = line_nlc_remainder[i];
		i++;
	}
	temp[i] = '\0';
	line = temp;  // use copy function?
	free (temp);
	return (line); // can i free line later in get_next_line? 
}


char *read_fd(int fd, char *line_nlc_remainder)
{
	char	*buffer;
	int		bytes_read;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);

	bytes_read = 1;
	while (!ft_strchr(line_nlc_remainder, '\n') && (bytes_read != 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_nlc_remainder = ft_strjoin(line_nlc_remainder, buffer);
	}
	free (buffer);
	return (line_nlc_remainder);
}


char *get_next_line(int fd)
{
	static char *substrings[FD_LIMIT + 1] = {NULL};
	char		*next_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0 || fd > FD_LIMIT) // fd >= FDLIMIT?
		return (NULL);

	substrings[fd] = read_fd(fd, substrings[fd]);
	if (substrings[fd] == NULL)
		return (NULL);

	next_line = get_line(substrings[fd]);
	substrings[fd] = get_remainder(substrings[fd]);
	return (next_line);
}





int	main(void)
{
	int fd1;
	// int fd2;
	// int fd3;

	fd1 = open("textfile1.txt", O_RDONLY);
	// fd2 = open("textfile2.txt", O_RDONLY);
	// fd3 = open("textfile3.txt", O_RDONLY);

	printf("%sThe fist		line of the file 1 = %s%s\n", BLUE, DEFAULT, get_next_line(fd1));
	printf("%sThe seccond	line of the file 1 = %s%s\n", BLUE, DEFAULT, get_next_line(fd1));
	printf("%sThe third		line of the file 1 = %s%s\n", BLUE, DEFAULT, get_next_line(fd1));
	
	// printf("%sThe fist		line of the file 2 = %s%s\n", RED, DEFAULT, get_next_line(fd2));
	// printf("%sThe seccond	line of the file 2 = %s%s\n", RED, DEFAULT, get_next_line(fd2));
	// printf("%sThe third		line of the file 2 = %s%s\n", RED, DEFAULT, get_next_line(fd2));
	
	// printf("%sThe fist		line of the file 3 = %s%s\n", GREEN, DEFAULT, get_next_line(fd3));
	// printf("%sThe seccond	line of the file 3 = %s%s\n", GREEN, DEFAULT, get_next_line(fd3));
	// printf("%sThe third		line of the file 3 = %s%s\n", GREEN, DEFAULT, get_next_line(fd3));

	return (0);
}


