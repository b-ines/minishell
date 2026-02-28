#include "ft_malloc.h"
#include <stdlib.h>

void	ft_free_all_malloc(void)
{
	t_malloc_list	**malloc_list;
	t_malloc_list	*node_to_free;

	malloc_list = get_malloc_list();
	while ((*malloc_list)->next != NULL)
	{
		if ((*malloc_list)->prev != NULL)
		{
			free((*malloc_list)->prev->ptr);
			free((*malloc_list)->prev);
		}
		*malloc_list = (*malloc_list)->next;
	}
}
