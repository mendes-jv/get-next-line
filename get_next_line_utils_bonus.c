/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:58:28 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/31 18:59:05 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		result;

	pointer = NULL;
	result = nmemb * size;
	if (!nmemb || !size || nmemb == result / size)
		pointer = malloc(result);
	if (pointer)
		while (result--)
			*(unsigned char *)(pointer + result) = 0;
	return (pointer);
}

char	*ft_strchr(char *str, int c)
{
	char	*first;

	first = NULL;
	if (!str)
		return (first);
	while (*str)
	{
		if (*str == (unsigned char)c)
		{
			first = (char *)str;
			break ;
		}
		str++;
	}
	if (!c || *str == (unsigned char)c)
		first = (char *)str;
	return (first);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	string = ft_calloc(length + ft_strlen(s2) + 1, sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, length + 1);
	while (*s2)
		string[length++] = *s2++;
	return (string);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	index;

	index = 0;
	while ((index + 1) < size && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	if (size)
		dst[index] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
