#include "ft_malloc.h"

int main()
{
	char *test1;
	char *test2;
	char *test3;
	char *test4;

	test1 = ft_malloc(sizeof(char) * 6);
	test2 = ft_malloc(sizeof(char) * 6);
	test3 = ft_malloc(sizeof(char) * 6);
	test4 = ft_malloc(sizeof(char) * 6);

	ft_free_malloc(test1);
	ft_free_malloc(test4);
	test2[0] = '\0';
	test3[0] = '\0';
	ft_free_all_malloc();

}
