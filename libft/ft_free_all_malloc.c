#include "libft.h"
#include <stdlib.h>

void	ft_free_all_malloc(void)
{
	t_malloc_list	**malloc_list;
	t_malloc_list	*node_to_free;

	malloc_list = get_malloc_list();
	while ((*malloc_list) != NULL)
	{
		node_to_free = *malloc_list;
		*malloc_list = (*malloc_list)->next;
		free(node_to_free->ptr);
		free(node_to_free);
	}
}
