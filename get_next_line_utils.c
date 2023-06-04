/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:58:28 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/31 18:59:05 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *str, int c)
{
	char	*first;

	first = NULL;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	length;

	length = ft_strlen(s1);
	string = ft_calloc(length + ft_strlen(s2) + 1, sizeof(char));
	if (string != NULL && s1 != NULL && s2 != NULL)
	{
		ft_strlcpy(string, s1, length + 1);
		while (*s2)
			string[length++] = *s2++;
		string[length] = '\0';
	}
	return (string);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
