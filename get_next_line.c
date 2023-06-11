/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:51:51 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/05 21:25:29 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp_buffer;
	static char	*buffer;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = ft_readline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_calloc(ft_linesize(buffer) + 1, sizeof(char));
	ft_strlcpy(line, buffer, ft_linesize(buffer) + 1);
	temp_buffer = buffer;
	buffer = ft_buffdup(temp_buffer + ft_linesize(temp_buffer));
	free(temp_buffer);
	return (line);
}

size_t	ft_linesize(char *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\n' && string[index])
		index++;
	return (index + 1);
}

char	*ft_readline(int fd, char *buffer)
{
	char	*read_buffer;
	char	*temp_buffer;
	ssize_t	bytes_read;

	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp_buffer = buffer;
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		temp_buffer = buffer;
		buffer = ft_strjoin(temp_buffer, read_buffer);
		free(temp_buffer);
	}
	free(read_buffer);
	return (buffer);
}

char	*ft_buffdup(char *s)
{
	char	*destiny;

	destiny = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (destiny != NULL && s != NULL)
		ft_strlcpy(destiny, s, BUFFER_SIZE);
	return (destiny);
}
