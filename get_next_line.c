/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:51:51 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/31 18:51:55 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	t_list		*buffers;
	char		*line;

	read(fd, buffer, BUFFER_SIZE);
	buffers = ft_lstnew(buffer);
	while (ft_strchr(buffer, '\n') && read(fd, buffer, BUFFER_SIZE))
		ft_lstadd_back(&buffers, ft_lstnew(buffer));
	line = ft_lstmapstr(buffers, ft_strcat);
	ft_lstclear(&buffers, &free);
	return (line);
}

void	ft_strcat(char *dst, const char *src)
{
	size_t	index;
	size_t	destiny_length;

	index = 0;
	destiny_length = ft_strlen(dst);
	while (src[index])
	{
		dst[destiny_length + index] = src[index];
		index++;
	}
	dst[destiny_length + index] = '\0';
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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_lstmapstr(t_list *lst, void (*f)(char *, const char *))
{
	char	*string;

	if (!lst)
		return (NULL);
	string = malloc(((ft_lstsize(lst) * BUFFER_SIZE) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (lst)
	{
		f(string, lst->content);
		lst = lst->next;
	}
	return (string);
}
