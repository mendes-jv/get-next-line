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
	char	*buffer;

	buffer = NULL;
	while (read(fd, buffer, BUFFER_SIZE))
		if (ft_strchr(buffer, BUFFER_SIZE))
			break;
	return (buffer);
}
