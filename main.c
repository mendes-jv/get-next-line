/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:07:11 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/01 18:07:18 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
  int   fd_two;
	int		index;
	char	*gnl;

	fd = open("test.txt", O_RDONLY);
  fd_two = open("test", O_RDONLY);
	index = 9;
	while (index--)
	{
		gnl = get_next_line(fd);
		if (gnl)
			printf("%s", gnl);
		else
			printf("%s", "NULL");
		free(gnl);
    gnl = get_next_line(fd_two);
    if (gnl)
      printf("%s", gnl);
    else
      printf("%s", gnl);
    free(gnl);
	}
	close(fd);
}
