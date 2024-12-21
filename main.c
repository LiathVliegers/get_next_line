/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: livliege <livliege@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/17 21:13:03 by livliege      #+#    #+#                 */
/*   Updated: 2024/12/21 15:51:42 by livliege      ########   odam.nl         */
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
	int		line_number;
	char	*line;
	int		fd;

	fd = open("txt_files/empty", O_RDONLY);
	line_number = 1;
	line = get_next_line(fd);
	if (!line)
	{
		printf("%s", line);
		free(line);
		return (0);
	}
	printf("%sLine #%d = %s%s", BLUE, line_number, DEFAULT, line);
	line_number++;
	while ((line = get_next_line(fd)))
	{
		printf("%sLine #%d = %s%s", BLUE, line_number, DEFAULT, line);
		free(line);
		line_number++;
	}
	close(fd);
	return (0);
}
