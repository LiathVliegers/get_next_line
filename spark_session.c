/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spark_session.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:12:32 by livliege          #+#    #+#             */
/*   Updated: 2023/11/28 17:25:44 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #include <stdlib.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>

// #ifndef BUFFER_SIZE
// #define BUFFER_SIZE 1024
// #endif

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int	i;
// 	char			*str;

// 	if (s == NULL)
// 		return (NULL);
// 	if (len == 0 || ft_strlen(s) < start)
// 		return (ft_strdup(""));
// 	if (start + len > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	str = (char *)malloc(sizeof(char) * (len + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[start] != '\0' && len != 0)
// 	{
// 		str[i] = s[start];
// 		i++;
// 		start++;
// 		len--;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// // -------------------------------------------------------------------------------

// char	*get_next_line(int fd)
// {
// 	static char buffer[BUFFER_SIZE];
// 	static int start = 0;
// 	int bytes_read;
// 	int len;
// 	char *next_line;
	
// 	len = 0;
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
	
// 	if (bytes_read <= 0)
// 		return (NULL);
	
// 	printf("%d bytes read!\n", bytes_read);
	
// 	while((start + len < bytes_read) && (buffer[start + len] != '\n') /* && (buffer[start + len] != '\0') */ )
// 		len++;
	
// 	next_line = ft_substr(buffer, start, len);
// 	start = start + len + 1;
	
// 	return(next_line);
// }

// int	main(void)
// {
// 	int fd;
// 	int nb;
// 	char *line;

// 	nb = 1;
// 	fd = open("textfile.txt", O_RDONLY);
	
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line %d is: %s\n", nb, line);
// 		nb++;
// 		free(line);
// 	}
	
// 	// line = get_next_line(fd);
// 	// printf("The fist line of the file = %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("The seccond line of the file = %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("The third line of the file = %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("The fourth line of the file = %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("The fifth line of the file = %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("The sixth line of the file = %s\n", line);
// 	// line = get_next_line(fd);
// 	// printf("The seventh line of the file = %s\n", line);
	
// 	// instead of using printf, we should make a variable to store the output of get_next_line and then free that variable
	
// 	return (0);
// }


// // TO DO:
// // We now need to keep track of IF we found a '\n', and if so, WHERE we found the '\n'.
// // We can use ft_strjoin to join strings together in case our BUFFER_SIZE=n is very small.
// // 
// // USE FREE TO FIX LEAKS
// // protect malloc





// char	*get_next_line(int fd)
// {
// 	static char buffer[BUFFER_SIZE];
// 	static int start = 0;
// 	ssize_t bytes_read;
// 	int len;
// 	char *next_line;
	
// 	len = 0;
// 	bytes_read = read(fd, buffer, BUFFER_SIZE);
	
// 	if (bytes_read <= 0)
// 		return (NULL);
	
// 	printf("%d bytes read!\n", bytes_read);
	
// 	while((start + len < bytes_read) && (buffer[start + len] != '\n'))
// 		len++;
	
// 	next_line = ft_substr(buffer, start, len);
// 	start = start + len + 1;
	
// 	return(next_line);
// }

// int	main(void)
// {
// 	int fd;
// 	int nb;
// 	char *line;

// 	nb = 1;
// 	fd = open("textfile.txt", O_RDONLY);
	
// 	while((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line %d is: %s\n", nb, line);
// 		nb++;
// 		free(line);
// 	}
// 	return (0);
// }



// // GOOD VERSION 26-11-2023!!

// #include "get_next_line.h"

// // take these out:
// #include <stdio.h>
// // did you take out the forbidden headers?

// #define RED "\033[91m"
// #define GREEN "\033[92m"
// #define BLUE "\033[94m"
// #define DEFAULT "\033[0m"

// # define MY_BUFFER 1024

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 10
// #endif

// char	*get_next_line(int fd)
// {
// 	static char	buffer[MY_BUFFER + 1] = {NULL};
// 	int			bytes_read;

// 	while((bytes_read = read(fd, buffer, BUFFER_SIZE)))		//read returns the number of bytes read, -1 for errors and 0 for end of file
// 	{
// 		buffer[bytes_read] = '\0';
// 		printf("%sbytes read: %d%s\n", RED, bytes_read, DEFAULT);
// 		printf("%sbuffer =%s %s\n", GREEN, DEFAULT, buffer);
// 	}
// 	return (buffer);
// }

// int	main(void)
// {
// 	int	fd;
	
// 	fd = open("textfile2.txt", O_RDONLY);
// 	printf("%sfd = %d%s\n", BLUE, fd, DEFAULT);
// 	get_next_line(fd);
	
// 	return (0);
// }


// TO DO:
// We now need to keep track of IF we found a '\n', and if so, WHERE we found the '\n'.
// We can use ft_strjoin to join strings together in case our BUFFER_SIZE=n is very small.
// 
// USE FREE TO FIX LEAKS
// protect malloc




// UNDERSTANDING THIS GITHUB VERSION:

#include "get_next_line.h"


#define RED "\033[91m"
#define GREEN "\033[92m"
#define BLUE "\033[94m"
#define DEFAULT "\033[0m"

# define BIG_BUFFER 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif


// delete line find
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	// find len of first line
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if eol == \0 return NULL
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	// len of file - len of firstline + 1
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	// line == buffer
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

// take line for return
char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!buffer[i])
		return (NULL);
	// go to the eol
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

// join and free
char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	// malloc if res dont exist
	if (!res)
		res = ft_calloc(1, 1);
	// malloc buffer
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		// while not eof read
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		// 0 to end for leak
		buffer[byte_read] = 0;
		// join and free
		res = ft_free(res, buffer);
		// quit if \n find
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	// error handling
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}


int	main(void)
{
	int		fd;
	int 	line_nbr = 1;
	char	*str;
	
	fd = open("textfile.txt", O_RDONLY);
	printf("%sfd = %d%s\n", BLUE, fd, DEFAULT);
	
	while((str = get_next_line(fd)))
	{
		printf("%sline #%d:%s %s", RED, line_nbr, DEFAULT, str);
		line_nbr++;
	}
	ft_putchar('\n');
	return (0);
}
























// #include "get_next_line.h"

// #define RED "\033[91m"
// #define GREEN "\033[92m"
// #define BLUE "\033[94m"
// #define DEFAULT "\033[0m"

// # define BIG_BUFFER 1024

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 20
// #endif


// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t			i;
// 	unsigned char	ch;

// 	ch = (unsigned char)c;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == ch)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	if (!ch && s[i] == '\0')
// 		return ((char *)s + i);
// 	return (NULL);
// }


// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }


// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*str;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	str = (char *)malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))) + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i] != '\0')
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		str[i + j] = s2[j];
// 		j++;
// 	}
// 	str[i + j] = '\0';
// 	return (str);
// }

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;

// 	if (size != 0 && (nmemb * size) / size != nmemb)
// 		return (NULL);
// 	ptr = malloc(nmemb * size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_bzero(ptr, (nmemb * size));
// 	return (ptr);
// }


// void	ft_bzero(void *s, size_t n)
// {
// 	ft_memset(s, 0, n);
// }


// void	*ft_memset(void *s, int c, size_t n)
// {
// 	char	*str;

// 	str = (char *)s;
// 	while (n != 0)
// 	{
// 		str[n - 1] = c;
// 		n--;
// 	}
// 	return (s);
// }



// char	*ft_new_line(char *buffer)
// {
// 	char	*new_line;
// 	int		i;

// 	i = 0;
// 	// TODO: ErrorHandling if buffer is empty
// 	while((buffer[i] != '\0') && (buffer[i] != '\n'))
// 	{
// 		i++;
// 	}
// 	new_line = ft_calloc(i + 1, sizeof(char));
// 	i = 0;
// 	while((buffer[i] != '\0') && (buffer[i] != '\n'))
// 	{
// 		new_line[i] = buffer[i];
// 		i++;
// 	}
// 	new_line[i] = '\n';
// 	return (new_line);
// }

// char	*ft_new_buffer(char *buffer)
// {
// 	int		i;
// 	int 	j;
// 	char	*new_buffer;

// 	// TODO: Errorhandling if buffer is empty
// 	i = 0;
// 	j = 0;
// 	while((buffer[i] != '\0') && (buffer[i] != '\n'))
// 	{
// 		i++;
// 	}
// 	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
// 	i += 1;
// 	while(buffer[i] != '\0')
// 	{
// 		new_buffer[j] = buffer[i];
// 		i++;
// 		j++;
// 	}
// 	// TODO: Free shit
// 	return(new_buffer);
// }

// char	*read_fd(int fd, char *buffer)
// {
// 	// char		*new_line;
// 	int			bytes_read;
	
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
// 	bytes_read = 1;
	
// 	while(bytes_read > 0) 
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		// TODO: ERROR HANDLING HERE
// 		buffer[bytes_read] = '\0';
// 	}
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*next_line;
	
// 	// TODO: ERROR HANDLING in case fd < 0 or buffersize < 0
// 	buffer = read_fd(fd, buffer); 
// 	// TODO: more error handling goes here
// 	next_line = ft_new_line(buffer); 
// 	buffer = ft_new_buffer(buffer); 
// 	return (next_line);
// }

// int	main(void)
// {
// 	int		fd;
// 	int 	line_nbr = 1;
// 	char	*str;
	
// 	fd = open("textfile.txt", O_RDONLY);
// 	printf("%sfd = %d%s\n", BLUE, fd, DEFAULT);
	
// 	while((str = get_next_line(fd)))
// 	{
// 		printf("%sline #%d:%s %s", RED, line_nbr, DEFAULT, str);
// 		line_nbr++;
// 	}
// 	ft_putchar('\n');
// 	return (0);
// }








#include "get_next_line.h"

#define RED "\033[91m"
#define GREEN "\033[92m"
#define BLUE "\033[94m"
#define DEFAULT "\033[0m"

# define BIG_BUFFER 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while((buffer[i] != '\0') && (buffer[i] != '\n'))
	{
		i++;
	}
	new_line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while((buffer[i] != '\0') && (buffer[i] != '\n'))
	{
		new_line[i] = buffer[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_new_buffer(char *buffer)
{
	int		i;
	int 	j;
	char	*new_buffer;

	i = 0;
	j = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while((buffer[i] != '\0') && (buffer[i] != '\n'))
	{
		i++;
	} // i now is at the eol or '\n'
	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i += 1;
	while(buffer[i] != '\0')
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return(new_buffer);
}

char	*ft_append(char *buffer, char *new_line)
{
	char	*temp;
	
	temp = ft_strjoin(buffer, new_line);
	free(buffer);
	return(temp);
}

char	*read_fd(int fd, char *buffer)
{
	char		*new_line;
	int			bytes_read;
	
	new_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	
	while(bytes_read > 0) /*while not at eof*/
	{
		bytes_read = read(fd, new_line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		new_line[bytes_read] = '\0';
		buffer = ft_append(buffer, new_line);
		if(ft_strchr(new_line, '\n'))
			break;
	}
	free(new_line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_fd(fd, buffer); /*this function reads the fd and puts all the characters up untill BUFFER_SIZE in buffer*/
	if (!buffer)
		return (NULL);
	next_line = ft_new_line(buffer); /*here goes a function that copies the characters before the '\n' into the next_line*/
	buffer = ft_new_buffer(buffer); /*here goes a function that saves all the characters AFTER the '\n' in buffer*/
	return (next_line);
}

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
