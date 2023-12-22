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





int	main(void)
{
	int		fd;
	int 	line_nbr = 1;
	char	*str;
	
	fd = open("textfile.txt", O_RDONLY);
	printf("%sfd = %d%s\n", BLUE, fd, DEFAULT);
	
	// str = get_next_line(fd);
	// printf("%s", str);

	while((str = get_next_line(fd)))
	{
		printf("%sline #%d:%s %s", RED, line_nbr, DEFAULT, str);
		line_nbr++;
	}
	// ft_putchar('\n');
	return (0);
}













// VINCENT'S VERSION:

#include "get_next_line.h"

#include <unistd.h>
#include <stdio.h>

#define MAX_FD	1024

static void	free_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*create_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	if (nl_position == 0)
	{
		if (**buffer == '\0')
			return (free_null(buffer), NULL);
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	res = ft_substr(*buffer, 0, nl_position);
	if (res == NULL)
		return (free_null(buffer), NULL);
	tmp = *buffer;
	*buffer = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	free(tmp);
	if (*buffer == NULL)
		return (free_null(&res), NULL);
	return (res);
}

char	*read_line(int fd, char **buffer, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*new_line;
	char	*tmp;

	new_line = ft_strchr(*buffer, '\n');
	while (new_line == NULL)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_null(buffer), NULL);
		if (bytes_read == 0)
			return (create_line(0, buffer));
		read_buffer[bytes_read] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(*buffer, read_buffer);
		free(tmp);
		if (*buffer == NULL)
			return (NULL);
		new_line = ft_strchr(*buffer, '\n');
	}
	return (create_line(new_line - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD + 1] = {NULL};
	char		*line;
	char		*read_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buffer == NULL)
		return (free_null(&buffers[fd]), NULL);
	if (buffers[fd] == NULL)
	{
		buffers[fd] = ft_strdup("");
		if (buffers[fd] == NULL)
			return (free_null(&read_buffer), NULL);
	}
	line = read_line(fd, &buffers[fd], read_buffer);
	free(read_buffer);
	return (line);
}
