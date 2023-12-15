/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2023/12/13 16:13:29 by livliege         ###   ########.fr       */
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

# define FD_LIMIT 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*readline(int fd, char *buffer)
{
	static char *substrings[FD_LIMIT];
	char *line;
	int bytes_read;
	
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer);
		if (ft_strchr(buffer, '\n')
		{
			...
		}
		line = ft_strjoin(line, buffer);
	}
}


char	*get_next_line(int fd)
{
	char *buffer;
	char *next_line;
	
	buffer = (char *)malloc((sizeof char * BUFFER_SIZE) + 1);
	next_line = readline(fd, buffer);
	return (next_line);
}

int	main(void)
{
	int		fd1;
	int		fd2;

	fd1 = open("textfile.txt", O_RDONLY);
	fd2 = open("textfile2.txt", O_RDONLY);

	printf("%sfd1 = %d%s\n", BLUE, fd1, DEFAULT);
	printf("%sfd2 = %d%s\n", BLUE, fd2, DEFAULT);
	
	return (0);
}

