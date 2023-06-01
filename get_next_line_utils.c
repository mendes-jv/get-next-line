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

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = node;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	while (*lst)
	{
		temp_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(temp_node, del);
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (!lst || !del)
		return ;
	temp_node = lst;
	del(temp_node->content);
	lst = lst->next;
	free(temp_node);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	index;
	t_list	*node;

	index = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		index++;
	}
	return (index);
}
