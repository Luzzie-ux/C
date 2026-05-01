# include "struct.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if(!content)
		return NULL;
	node->content = content;
	node->next = NULL;
	return node;
}


