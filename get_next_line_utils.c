/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:29:03 by livliege          #+#    #+#             */
/*   Updated: 2023/12/22 21:14:23 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	if (s == NULL)
		return (NULL);
	ch = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (!ch && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		strlen1;
	int 	strlen2;
	int		i;
	int		j;
	char	*str;

	// if (s1 && !s2)
	// 	return ((char *)s1);
	// if (!s1 && s2)
	// 	return ((char *)s2);
	// if (s1 == NULL || s2 == NULL)
	// 	return (NULL);
	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (strlen1 + strlen2 + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < strlen2)
	{
		str[strlen1 + i] = s2[i];
		i++;
	}
	j = 0;
	while (j < strlen1)
	{
		str[j] = s1[j];
		j++;
	}
	// i = 0;
	// j = 0;
	// while (s1 && s1[i] != '\0')
	// {
	// 	str[i] = s1[i];
	// 	i++;
	// }
	// while (s2[j] != '\0')
	// {
	// 	str[i + j] = s2[j];
	// 	j++;
	// }
	// str[i + j] = '\0';
	return (str);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char	*dest1;
// 	unsigned char	*src1;
// 	size_t			i;

// 	dest1 = (unsigned char *)dest;
// 	src1 = (unsigned char *)src;
// 	if (dest1 == src1 || n == 0)
// 		return (dest);
// 	if (dest1 > src1 && dest1 - src1 < (int)n)
// 	{
// 		i = n;
// 		while (i > 0)
// 		{
// 			dest1[i - 1] = src1[i - 1];
// 			i--;
// 		}
// 		return (dest);
// 	}
// 	else
// 	{
// 		ft_memcpy(dest, src, n);
// 		return (dest);
// 	}
// }

