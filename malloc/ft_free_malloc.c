#include "ft_malloc.h"
#include <stdlib.h>

static t_malloc_list	*search_node(void *ptr, t_malloc_list *malloc_list)
{
	while ((malloc_list->ptr != ptr) && (malloc_list != NULL))
		malloc_list = malloc_list->next;
	return (malloc_list);
}

void	ft_free_malloc(void *ptr)
{
	t_malloc_list	**malloc_list;
	t_malloc_list	*ptr_node;
	t_malloc_list	*next_node_ptr;
	t_malloc_list	*prev_node_ptr;

	if (ptr == NULL)
		return ;
	// search ptr node
	malloc_list = get_malloc_list();
	ptr_node = search_node(ptr, *malloc_list);
	free(ptr_node->ptr);
	next_node_ptr = ptr_node->next;
	prev_node_ptr = ptr_node->prev;
	if (prev_node_ptr != NULL)
		prev_node_ptr->next = next_node_ptr;
	if (next_node_ptr != NULL)
		next_node_ptr->prev = prev_node_ptr;
	free(ptr_node);
}
