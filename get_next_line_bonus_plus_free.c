/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2024/01/17 20:36:48 by livliege         ###   ########.fr       */
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

static void	ft_free_null(char **free_array)
{
	if (*free_array)
	{
		free(*free_array);
		*free_array = NULL;
	}
}

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
		return (ft_free_null(&line_nlc_remainder), NULL);
	while (line_nlc_remainder[nlc] != '\0')
	{
		remainder[i] = line_nlc_remainder[nlc];
		nlc++;
		i++;
	}
	ft_free_null(&line_nlc_remainder);
	remainder[i] = '\0';
	return (remainder);
}

char	*ft_get_line(char *line_nlc_remainder)
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
			ft_free_null(&line_nlc_remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_nlc_remainder = ft_strjoin(temp, buffer);
		if (!*line_nlc_remainder || line_nlc_remainder == NULL)
		{
			ft_free_null(&line_nlc_remainder);
			return (ft_free_null(&temp), NULL);
		}
		ft_free_null(&temp);
	}
	return (line_nlc_remainder);
}

char	*get_next_line(int fd)
{
	static char	*substrings[FD_LIMIT + 1] = {NULL};
	char		*next_line;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX || fd < 0 || fd >= FD_LIMIT)
		return (NULL);
	substrings[fd] = read_fd(fd, substrings[fd]);
	if (substrings[fd] == NULL)
		return (NULL);
	next_line = ft_get_line(substrings[fd]);
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
// 	char	*line;
// 	int		fd1 = open("textfile1.txt", O_RDONLY);
// 	int		fd2 = open("textfile2.txt", O_RDONLY);
// 	int		fd3 = open("textfile3.txt", O_RDONLY);	
// 	int		fd4 = open("textfile4.txt", O_RDONLY);
// 	int		fd5 = open("textfile5.txt", O_RDONLY);
// 	int		fd6 = open("textfile6.txt", O_RDONLY);	
// 	int		fd7 = open("textfile7.txt", O_RDONLY);
// 	int		fd8 = open("textfile8.txt", O_RDONLY);
// 	int		fd9 = open("textfile9.txt", O_RDONLY);	
// 	int		fd10 = open("textfile10.txt", O_RDONLY);

// 	int 	fsoares_fd1 = open("fsoares_txt_files/1char.txt", O_RDONLY);
// 	int 	fsoares_fd2 = open("fsoares_txt_files/empty.txt", O_RDONLY);
// 	int 	fsoares_fd3 = open("fsoares_txt_files/giant_line.txt", O_RDONLY);
// 	int 	fsoares_fd4 = open("fsoares_txt_files/giant_line_nl.txt", O_RDONLY);
// 	int 	fsoares_fd5 = open("fsoares_txt_files/lines_around_10.txt", O_RDONLY);
// 	int 	fsoares_fd6 = open("fsoares_txt_files/multiple_nl.txt", O_RDONLY);
// 	int 	fsoares_fd7 = open("fsoares_txt_files/one_line_no_nl.txt", O_RDONLY);
// 	int 	fsoares_fd8 = open("fsoares_txt_files/only_nl.txt", O_RDONLY);
// 	int 	fsoares_fd9 = open("fsoares_txt_files/read_error.txt", O_RDONLY);
// 	int 	fsoares_fd10 = open("fsoares_txt_files/variable_nls.txt", O_RDONLY);
	
// 	int		line_number = 1;

// 	// fsoares tests:
// 	while ((line = get_next_line(fsoares_fd1)))
// 	{
// 		printf("%sLine #%d of file 1char = %s%s", BLUE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd2)))
// 	{
// 		printf("%sLine #%d of file empty = %s%s", RED, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd3)))
// 	{
// 		printf("%sLine #%d of file giant_line = %s%s", YELLOW, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd4)))
// 	{
// 		printf("%sLine #%d of file giant_line_nl = %s%s", GREEN, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd5)))
// 	{
// 		printf("%sLine #%d of file lines_around_10 = %s%s", PURPLE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd6)))
// 	{
// 		printf("%sLine #%d of file multiple_nl = %s%s", BLUE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd7)))
// 	{
// 		printf("%sLine #%d of file one_line_no_nl = %s%s", RED, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd8)))
// 	{
// 		printf("%sLine #%d of file only_nl = %s%s", YELLOW, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd9)))
// 	{
// 		printf("%sLine #%d of file read_error = %s%s", GREEN, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}
// 	printf("\n");
// 	line_number = 1;
// 	while ((line = get_next_line(fsoares_fd10)))
// 	{
// 		printf("%sLine #%d of file variable_nls = %s%s", PURPLE, line_number, DEFAULT, line);
// 		free(line);
// 		line_number++;
// 	}

// 	printf("\n");
// 	printf("------------------------------------------------------------------------------------------------------------------");
// 	printf("\n");

// 	// my testfiles:
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
