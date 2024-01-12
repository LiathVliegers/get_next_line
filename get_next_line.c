/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2024/01/12 20:03:01 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	remainder = (char *)malloc(sizeof(char) * \
	(ft_strlen(&line_nlc_remainder[nlc]) + 1));
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
		{
			return (free(temp), NULL);
		}
		free(temp);
	}
	return (line_nlc_remainder);
}

char	*get_next_line(int fd)
{
	static char	*substring;
	char		*next_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0 || fd > FD_LIMIT)
		return (NULL);
	substring = read_fd(fd, substring);
	if (substring == NULL)
		return (NULL);
	next_line = get_line(substring);
	if (next_line == NULL)
		return (NULL);
	substring = get_remainder(substring);
	if (substring == NULL)
		return (NULL);
	return (next_line);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int 	line_number;
// 	char 	*line;
// 	int 	fd;

// 	line_number = 1;
// 	fd = open("textfile2.txt", O_RDONLY);
// 	// fd = open("notes_get_next_line.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%sLine #%d = %s%s", BLUE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	return (0);
// }

// printf("%s\nline: %s%s%s\n", YELLOW, GREEN, line_nlc_remainder, DEFAULT);
