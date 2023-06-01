/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:59:51 by jovicto2          #+#    #+#             */
/*   Updated: 2023/05/31 19:15:48 by jovicto2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Mandatory
void				ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *str);
char				*ft_lstmapstr(t_list *lst, void (*f)(char *, const char *));
char				*get_next_line(int fd);

// Mandatory utils
void				ft_lstadd_back(t_list **lst, t_list *node);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstnew(void *content);
size_t				ft_lstsize(t_list *lst);

// Bonus

// Bonus utils

#endif
