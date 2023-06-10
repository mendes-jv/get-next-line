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
	char		*temp_line;
	static char	*remainder;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!remainder)
		remainder = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp_line = ft_readline(fd, remainder, temp_line);
	if (!temp_line)
	{
		free (remainder);
		free (temp_line);
		return (NULL);
	}
	line = ft_calloc(ft_linesize(temp_line) + 1, sizeof(char));
	ft_strlcpy(line, temp_line, ft_linesize(temp_line));
	ft_strlcpy(remainder, temp_line + ft_linesize(temp_line), BUFFER_SIZE);
	free(temp_line);
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

char	*ft_readline(int fd, char *remainder, char *temp_line)
{
	char	*buffer;
	char	*readed_chars;
	int		readed_length;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readed_length = 1;
	if (remainder)
		ft_strlcpy(temp_line, remainder, ft_strlen(remainder) + 1);
	while (!ft_strchr(temp_line, '\n') && readed_length)
	{
		readed_length = read(fd, buffer, BUFFER_SIZE);
		if (!readed_length)
			break ;
		buffer[BUFFER_SIZE] = '\0';
		readed_chars = temp_line;
		temp_line = ft_strjoin(readed_chars, buffer);
		free(readed_chars);
	}
	free(buffer);
	return (temp_line);
}
