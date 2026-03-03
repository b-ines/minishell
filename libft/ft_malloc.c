
#include <stdlib.h>
#include "libft.h"

void	*ft_malloc(unsigned int size)
{
	void			*ptr;
	t_malloc_list	*node;
	t_malloc_list	*it;
	t_malloc_list	**malloc_list;

	ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	node = malloc(sizeof(t_malloc_list));
	if (node == NULL)
		return (NULL);
	node->ptr = ptr;
	node->next = NULL;
	node->prev = NULL;
	malloc_list = get_malloc_list();
	if (malloc_list == NULL || (*malloc_list == NULL))
		*malloc_list = node;
	else
	{
		it = *malloc_list;
		while (it->next != NULL)
			it = it->next;
		it->next = node;
		node->prev = it;
	}
	return (ptr);
}
