#ifndef FT_MALLOC_H
# define FT_MALLOC_H

typedef struct s_malloc_list
{
	void					*ptr;
	struct s_malloc_list	*next;
	struct s_malloc_list	*prev;
}	t_malloc_list;

t_malloc_list	**get_malloc_list(void);
void			ft_free_all_malloc(void);
void			*ft_malloc(unsigned int size);
void			ft_free_malloc(void *ptr);


#endif
