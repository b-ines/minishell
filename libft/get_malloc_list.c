#include "libft.h"
#include <stdlib.h>

t_malloc_list	**get_malloc_list(void)
{
	static t_malloc_list	*head = NULL;
	return (&head);
}

