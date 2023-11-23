/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:12:32 by livliege          #+#    #+#             */
/*   Updated: 2023/11/23 15:50:31 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	if (len == 0 || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && len != 0)
	{
		str[i] = s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// -------------------------------------------------------------------------------


char	*get_next_line(int fd)
{
	char buffer[1024];
	int bytes_read;
	char *next_line;
	int len;
	static int start = 0;
	
	len = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));

	printf("%d bytes read!\n", bytes_read);
	
	while(buffer[start + len] != '\n')
		len++;
	
	next_line = ft_substr(buffer, start, len);
	start = start + len + 1;

	return(next_line);
}

int	main(void)
{
	int fd;

	fd = open("textfile.txt", O_RDONLY);
	printf("The fist line of the file = %s\n", get_next_line(fd));
	printf("The seccond line of the file = %s\n", get_next_line(fd));
	printf("The third line of the file = %s\n", get_next_line(fd));
	printf("The fourth line of the file = %s\n", get_next_line(fd));
	printf("The fifth line of the file = %s\n", get_next_line(fd));
	printf("The sixth line of the file = %s\n", get_next_line(fd));
	printf("The seventh line of the file = %s\n", get_next_line(fd));
	// instead of using printf, we should make a variable to store the output of get_next_line and then free that variable
	
	return (0);
}


// TO DO:
// We now need to keep track of IF we found a '\n', and if so, WHERE we found the '\n'.
// We can use ft_strjoin to join strings together in case our BUFFER_SIZE=n is very small.
// 
// USE FREE TO FIX LEAKS
// protect malloc
