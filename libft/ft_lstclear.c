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
