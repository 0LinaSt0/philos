/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:19:49 by msalena           #+#    #+#             */
/*   Updated: 2022/01/24 20:19:50 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save_nexts;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		save_nexts = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = save_nexts;
	}
}
