/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2023/11/29 19:04:06 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
https://gh.xxfe.com/topics/42-get-next-line
*/

#include "get_next_line.h"

// take these out:
#include <stdio.h>
// did you take out the forbidden headers?

#define RED "\033[91m"
#define GREEN "\033[92m"
#define BLUE "\033[94m"
#define DEFAULT "\033[0m"

# define MY_BUFFER_SIZE 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*read_fd(int fd, char *buffer)
{
	int			bytes_read;
	
	// bytes_read = read(fd, buffer, BUFFER_SIZE);		//read returns the number of bytes read, -1 for errors and 0 for end of file
	// printf("%sbytes read: %d%s\n", RED, bytes_read, DEFAULT);
	while((bytes_read = read(fd, buffer, BUFFER_SIZE)))
	{
		printf("%sbytes read: %d%s\n", RED, bytes_read, DEFAULT);
		
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}


char	*get_next_line(int fd)
{
	static char	buffer[MY_BUFFER_SIZE + 1];
	char		*next_line;
	
	next_line = read_fd(fd, buffer);
	
	return (next_line);
}

int	main(void)
{
	int		fd;
	int		fd2;

	char	*next_line;

	fd = open("textfile.txt", O_RDONLY);
	fd2 = open("textfile2.txt", O_RDONLY);

	printf("%sfd = %d%s\n", BLUE, fd, DEFAULT);
	printf("%sfd2 = %d%s\n", BLUE, fd2, DEFAULT);

	next_line = ft_calloc(MY_BUFFER_SIZE, sizeof(char));
	
	next_line = get_next_line(fd);
	printf("%sfirst line = %s%s\n", GREEN, DEFAULT, next_line);
	
	// next_line = get_next_line(fd);
	// printf("%sseccond line = %s%s\n", GREEN, DEFAULT, next_line);
	return (0);
}

