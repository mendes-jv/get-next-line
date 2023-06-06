/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:59:51 by jovicto2          #+#    #+#             */
/*   Updated: 2023/06/05 21:24:20 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Mandatory
char	*get_next_line(int fd);
size_t	ft_linesize(char *string);
char	*ft_readline(int fd, char *remainder, char *temp_line);

// Mandatory utils
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

// Bonus

// Bonus utils

#endif
