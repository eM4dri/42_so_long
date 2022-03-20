/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:19:51 by emadriga          #+#    #+#             */
/*   Updated: 2021/06/04 18:37:58 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*auxlst;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		auxlst = ft_lstnew((*f)(lst->content));
		if (!auxlst)
		{
			ft_lstclear(&newlst, del);
			break ;
		}
		ft_lstadd_back(&newlst, auxlst);
		lst = lst->next;
	}
	return (newlst);
}
