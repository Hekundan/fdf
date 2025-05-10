/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:16:19 by johartma          #+#    #+#             */
/*   Updated: 2024/11/28 13:34:54 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_check_new_list(void *content, t_list *new_node, 
t_list *lst, void (*del)(void *))
{
	if (!new_node)
	{
		del(content);
		ft_lstclear(&lst, del);
		return (0);
	}
	else
		return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start_new_list;
	t_list	*new_node;
	void	*content;

	if (!(lst && f && del))
		return (NULL);
	content = f(lst->content);
	start_new_list = ft_lstnew(content);
	if (!ft_check_new_list(content, start_new_list, start_new_list, del))
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!ft_check_new_list(content, new_node, start_new_list, del))
			return (0);
		ft_lstadd_back(&start_new_list, new_node);
	}
	return (start_new_list);
}
