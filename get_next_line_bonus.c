/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:59:09 by livliege          #+#    #+#             */
/*   Updated: 2024/01/17 21:18:41 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			free(line_nlc_remainder);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_nlc_remainder = ft_strjoin(temp, buffer);
		if (!*line_nlc_remainder || line_nlc_remainder == NULL)
		{
			free(line_nlc_remainder);
			return (free(temp), NULL);
		}
		free(temp);
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
