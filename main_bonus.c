/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:13:13 by livliege          #+#    #+#             */
/*   Updated: 2024/01/17 21:15:10 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define PURPLE "\033[35m"
#define LIGHTBLUE "\033[36m"
#define DEFAULT "\033[0m"

int	main(void)
{
	int 	line_number;
	char 	*line;
	int 	fd1;
	int 	fd2;
	int 	fd3;	
	int 	fd4;
	int 	fd5;
	int 	fd6;	
	int 	fd7;
	int 	fd8;
	int 	fd9;	
	int 	fd10;

	line_number = 1;
	fd1 = open("textfile1.txt", O_RDONLY);
	fd2 = open("textfile2.txt", O_RDONLY);
	fd3 = open("textfile3.txt", O_RDONLY);	
	fd4 = open("textfile4.txt", O_RDONLY);
	fd5 = open("textfile5.txt", O_RDONLY);
	fd6 = open("textfile6.txt", O_RDONLY);	
	fd7 = open("textfile7.txt", O_RDONLY);
	fd8 = open("textfile8.txt", O_RDONLY);
	fd9 = open("textfile9.txt", O_RDONLY);	
	fd10 = open("textfile10.txt", O_RDONLY);

	while ((line = get_next_line(fd1)))
	{
		printf("%sLine #%d of file 1 = %s%s", BLUE, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd2)))
	{
		printf("%sLine #%d of file 2 = %s%s", RED, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd3)))
	{
		printf("%sLine #%d of file 3 = %s%s", YELLOW, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd4)))
	{
		printf("%sLine #%d of file 4 = %s%s", GREEN, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd5)))
	{
		printf("%sLine #%d of file 5 = %s%s", PURPLE, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd6)))
	{
		printf("%sLine #%d of file 6 = %s%s", BLUE, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd7)))
	{
		printf("%sLine #%d of file 7 = %s%s", RED, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd8)))
	{
		printf("%sLine #%d of file 8 = %s%s", YELLOW, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd9)))
	{
		printf("%sLine #%d of file 9 = %s%s", GREEN, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	printf("\n");
	line_number = 1;
	while ((line = get_next_line(fd10)))
	{
		printf("%sLine #%d of file 10 = %s%s", PURPLE, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	return (0);
}
