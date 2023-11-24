/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2023/11/24 20:29:33 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif



// char	*get_next_line(int fd)
// {


// }

int	main(void)
{
	int fd;
	char	buffer[256];
	int		bytes_read;
	
	fd = open("textfile2.txt", O_RDONLY);

	while((bytes_read = read(fd, buffer, BUFFER_SIZE)))		//read returns the number of bytes read, -1 for errors and 0 for end of file
	{
		buffer[bytes_read] = '\0';
		printf("buffer = %s\n", buffer);
	}
	return (0);
}


// TO DO:
// We now need to keep track of IF we found a '\n', and if so, WHERE we found the '\n'.
// We can use ft_strjoin to join strings together in case our BUFFER_SIZE=n is very small.
// 
// USE FREE TO FIX LEAKS
// protect malloc

