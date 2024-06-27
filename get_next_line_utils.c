/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:20:21 by alexigar          #+#    #+#             */
/*   Updated: 2024/02/05 18:37:56 by alexigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*to_return;
	int		i;
	int		j;

	to_return = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (to_return == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		to_return[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		to_return[j] = s2[i];
		i++;
		j++;
	}
	to_return[j] = '\0';
	return (to_return);
}

char	*ft_strchr(char *s, int c)
{
	char	character;

	character = c;
	while (*s)
	{
		if (*s == character)
			return (s);
		s++;
	}
	if (character == '\0')
		return (s);
	return (NULL);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_calloc(int count, int size)
{
	char	*to_return;
	int		total_size;
	int		i;

	total_size = count * size;
	to_return = malloc(total_size);
	if (to_return == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		to_return[i] = '\0';
		i++;
	}
	return (to_return);
}
