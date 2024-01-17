/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:44:49 by livliege          #+#    #+#             */
/*   Updated: 2024/01/17 14:00:22 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define FD_LIMIT 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// buffer > 1000000 return null

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
char	*get_next_line(int fd);
char	*ft_get_line(char *line_nlc_remainder);

#endif
