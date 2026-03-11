/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:45:03 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/10 17:03:28 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

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
int				ft_atoi(const char *str);
long long		ft_atol(const char *str);
void			ft_bzero(void *str, size_t len);
void			*ft_calloc(size_t num, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *search, int to_find, size_t size);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t size);
void			*ft_memmove(void *dest, const void *src, size_t size);
void			*ft_memset(void *pointer, int value, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
char			*ft_strndup(char *src, int len);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t size);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *search, const char *to_f, size_t len);
char			*ft_strrchr(const char *str, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_free_split(char **split);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **list, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
void			ft_swap_str(char **ptr1, char **ptr2);
int				ft_n_index(char *str);
void			*ft_free(char **to_free, void *to_return);
char			*ft_strjoin_gnl(char *stash, char *buffer);
char			*get_next_line(int fd);

#endif
