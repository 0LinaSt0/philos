#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*kak;

	kak = (t_list *)malloc(sizeof(t_list));
	if (kak == NULL)
		return (NULL);
	kak->content = content;
	kak->next = NULL;
	return (kak);
}
