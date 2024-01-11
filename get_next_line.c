/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2024/01/11 19:45:01 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// inspiration: 
// https://github.com/ayogun/get_next_line/blob/main/get_next_line_bonus.c

#include "get_next_line.h"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define PURPLE "\033[35m"
#define LIGHTBLUE "\033[36m"
#define DEFAULT "\033[0m"

char *get_remainder(char *line_nlc_remainder)
{
	char 	*remainder;
	int		nlc;
	int		i;

	i = 0;
	nlc = 0;
	if (line_nlc_remainder[i] == '\0')
		return (line_nlc_remainder);
	while (line_nlc_remainder[nlc] != '\0' && line_nlc_remainder[nlc] != '\n')
		nlc++;
	if (line_nlc_remainder[nlc] == '\n')
	{
		nlc++;
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(&line_nlc_remainder[nlc]) + 1));
	if (remainder == NULL)
		return (free(line_nlc_remainder), NULL);
	while (line_nlc_remainder[nlc] != '\0')
	{
		remainder[i] = line_nlc_remainder[nlc];
		nlc++;
		i++;
	}
	remainder[i] = '\0';
	return (remainder);
}

char *get_line(char *line_nlc_remainder)
{
	char 	*line;
	int		i;
	int		nlc;

	i = 0;
	nlc = 0;
	if (line_nlc_remainder[nlc] == '\0')
		return (free(line_nlc_remainder), NULL);
	while (line_nlc_remainder[nlc] != '\0' && line_nlc_remainder[nlc] != '\n')
		nlc++;
	line = (char *)malloc(sizeof(char) * (nlc + 2));
	if (line == NULL) // line_nlc_remainder hangt nog open
		return (NULL);
	while (line_nlc_remainder[i] != '\0' && line_nlc_remainder[i] != '\n')
	{
		line[i] = line_nlc_remainder[i];
		i++;
	}
	if (line_nlc_remainder[i] == '\n')
	{
		line[i] = line_nlc_remainder[i];
		i++;
	}
	line[i] = '\0';
	return (line); // can i free line later in get_next_line? 
}


char *read_fd(int fd, char *line_nlc_remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;
	
	bytes_read = 1;
	while (ft_strchr(buffer, '\n') == NULL && (bytes_read != 0))
	{
		temp = line_nlc_remainder;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		
		printf("buffer: %s%s%s\n", RED, buffer, DEFAULT);

		if (bytes_read < 0)
		{
			free(line_nlc_remainder);			
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_nlc_remainder = ft_strjoin(temp, buffer);
		
		printf("line: %s%s%s\n", GREEN, line_nlc_remainder, DEFAULT);
		
		if (line_nlc_remainder == NULL)
		{
			return (free(temp), NULL);
		}
		free(temp);
	}
	return (line_nlc_remainder);
}

char *get_next_line(int fd)
{
	static char *substrings[FD_LIMIT + 1] = {NULL};
	char		*next_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0 || fd > FD_LIMIT)
	{
		return (NULL);
	}
	substrings[fd] = read_fd(fd, substrings[fd]);
	if (substrings[fd] == NULL)
	{
		return (NULL);
	}
	next_line = get_line(substrings[fd]);
	if (next_line == NULL)
	{
		return (NULL);
	}
	substrings[fd] = get_remainder(substrings[fd]);
	if (substrings[fd] == NULL)
	{
		return (NULL);
	}
	return (next_line);
}


int	main(void)
{
	int 	line_number;
	char 	*line;
	int 	fd1;
	// int 	fd2;
	// int 	fd3;
	
	line_number = 1;
	fd1 = open("textfile1.txt", O_RDONLY);
	// fd2 = open("textfile2.txt", O_RDONLY);
	// fd3 = open("textfile3.txt", O_RDONLY);

	while ((line = get_next_line(fd1)))
	{
		printf("%sLine #%d of file 1 = %s%s", BLUE, line_number, DEFAULT, line);
		line_number++;
	}


	// printf("%sThe fist	line of the file 1 = %s%s", BLUE, DEFAULT, get_next_line(fd1));
	// printf("%sThe seccond	line of the file 1 = %s%s", BLUE, DEFAULT, get_next_line(fd1));
	// printf("%sThe third	line of the file 1 = %s%s", BLUE, DEFAULT, get_next_line(fd1));
	// printf("%sThe fourth	line of the file 1 = %s%s", BLUE, DEFAULT, get_next_line(fd1));
	// printf("%sThe fifth	line of the file 1 = %s%s", BLUE, DEFAULT, get_next_line(fd1));
	// printf("%sThe sixth	line of the file 1 = %s%s", BLUE, DEFAULT, get_next_line(fd1));
	
	// printf("%sThe fist		line of the file 2 = %s%s\n", RED, DEFAULT, get_next_line(fd2));
	// printf("%sThe seccond	line of the file 2 = %s%s\n", RED, DEFAULT, get_next_line(fd2));
	// printf("%sThe third		line of the file 2 = %s%s\n", RED, DEFAULT, get_next_line(fd2));
	
	// printf("%sThe fist		line of the file 3 = %s%s\n", GREEN, DEFAULT, get_next_line(fd3));
	// printf("%sThe seccond	line of the file 3 = %s%s\n", GREEN, DEFAULT, get_next_line(fd3));
	// printf("%sThe third		line of the file 3 = %s%s\n", GREEN, DEFAULT, get_next_line(fd3));

	return (0);
}


