#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *str);

// FUNCTIONS TO USE:
// ft_bzero
// ft_strjoin
// ft_strchr
// ft_calloc
// ft_strlen

void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);

#endif
