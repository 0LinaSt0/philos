/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:19:57 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:19:58 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst1;
	t_list	*new_lst2;

	new_lst2 = 0;
	while (lst != NULL)
	{
		new_lst1 = ft_lstnew(f(lst->content));
		lst = lst->next;
		ft_lstadd_back(&new_lst2, new_lst1);
		if (new_lst1 == NULL)
		{
			ft_lstclear(&new_lst2, del);
			return (0);
		}
	}
	return (new_lst2);
}
