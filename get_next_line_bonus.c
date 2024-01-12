/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2024/01/12 20:11:02 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define PURPLE "\033[35m"
#define LIGHTBLUE "\033[36m"
#define DEFAULT "\033[0m"

char	*get_remainder(char *line_nlc_remainder)
{
	char	*remainder;
	int		nlc;
	int		i;

	i = 0;
	nlc = 0;
	if (line_nlc_remainder[i] == '\0')
		return (line_nlc_remainder);
	while (line_nlc_remainder[nlc] != '\0' && line_nlc_remainder[nlc] != '\n')
		nlc++;
	if (line_nlc_remainder[nlc] == '\n')
		nlc++;
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(&line_nlc_remainder[nlc]) + 1));
	if (remainder == NULL)
		return (free(line_nlc_remainder), NULL);
	while (line_nlc_remainder[nlc] != '\0')
	{
		remainder[i] = line_nlc_remainder[nlc];
		nlc++;
		i++;
	}
	free(line_nlc_remainder);
	remainder[i] = '\0';
	return (remainder);
}

char	*get_line(char *line_nlc_remainder)
{
	char	*line;
	int		i;
	int		nlc;

	i = 0;
	nlc = 0;
	if (line_nlc_remainder[nlc] == '\0')
		return (NULL);
	while (line_nlc_remainder[nlc] != '\0' && line_nlc_remainder[nlc] != '\n')
		nlc++;
	line = (char *)malloc(sizeof(char) * (nlc + 2));
	if (line == NULL)
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
	return (line);
}

char	*read_fd(int fd, char *line_nlc_remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	while (ft_strchr(buffer, '\n') == NULL && (bytes_read != 0))
	{
		temp = line_nlc_remainder;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line_nlc_remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_nlc_remainder = ft_strjoin(temp, buffer);
		if (line_nlc_remainder == NULL)
			return (free(temp), NULL);
		free(temp);
	}
	return (line_nlc_remainder);
}

char	*get_next_line(int fd)
{
	static char	*substrings[FD_LIMIT + 1] = {NULL};
	char		*next_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0 || fd > FD_LIMIT)
		return (NULL);
	substrings[fd] = read_fd(fd, substrings[fd]);
	if (substrings[fd] == NULL)
		return (NULL);
	next_line = get_line(substrings[fd]);
	if (next_line == NULL)
		return (NULL);
	substrings[fd] = get_remainder(substrings[fd]);
	if (substrings[fd] == NULL)
		return (NULL);
	return (next_line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int 	line_number;
// 	char 	*line;
// 	int 	fd1;
// 	int 	fd2;
// 	int 	fd3;	
// 	int 	fd4;
// 	int 	fd5;
// 	int 	fd6;	
// 	int 	fd7;
// 	int 	fd8;
// 	int 	fd9;	
// 	int 	fd10;

// 	line_number = 1;
// 	fd1 = open("textfile1.txt", O_RDONLY);
// 	fd2 = open("textfile2.txt", O_RDONLY);
// 	fd3 = open("textfile3.txt", O_RDONLY);	
// 	fd4 = open("textfile4.txt", O_RDONLY);
// 	fd5 = open("textfile5.txt", O_RDONLY);
// 	fd6 = open("textfile6.txt", O_RDONLY);	
// 	fd7 = open("textfile7.txt", O_RDONLY);
// 	fd8 = open("textfile8.txt", O_RDONLY);
// 	fd9 = open("textfile9.txt", O_RDONLY);	
// 	fd10 = open("textfile10.txt", O_RDONLY);

// 	while ((line = get_next_line(fd1)))
// 	{
// 		printf("%sLine #%d of file 1 = %s%s", BLUE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd2)))
// 	{
// 		printf("%sLine #%d of file 2 = %s%s", RED, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd3)))
// 	{
// 		printf("%sLine #%d of file 3 = %s%s", YELLOW, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd4)))
// 	{
// 		printf("%sLine #%d of file 4 = %s%s", GREEN, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd5)))
// 	{
// 		printf("%sLine #%d of file 5 = %s%s", PURPLE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd6)))
// 	{
// 		printf("%sLine #%d of file 6 = %s%s", BLUE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd7)))
// 	{
// 		printf("%sLine #%d of file 7 = %s%s", RED, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd8)))
// 	{
// 		printf("%sLine #%d of file 8 = %s%s", YELLOW, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd9)))
// 	{
// 		printf("%sLine #%d of file 9 = %s%s", GREEN, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fd10)))
// 	{
// 		printf("%sLine #%d of file 10 = %s%s", PURPLE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	return (0);
// }
