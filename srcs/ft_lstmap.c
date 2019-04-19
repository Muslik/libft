/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorgil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:38:02 by dmorgil           #+#    #+#             */
/*   Updated: 2019/04/19 11:33:25 by dmorgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void	ft_free_list(t_list *lst)
{
	t_list *tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *tmp;
	t_list *begin;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_free_list(begin);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (begin);
}
