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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
