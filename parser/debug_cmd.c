#include "parser.h"

void    printf_tab(char **tab)
{
	int i = 0;
	if (!tab || !*tab)
		return ;
	printf("[ ");
	while (tab[i])
	{
		printf("%s, ", tab[i++]);
	}
	printf("0 ] ");
}

void printf_cmd(t_cmd *cmd)
{
	t_cmd *current;
	int	i = 1;

	current = cmd;
	if (!cmd)
		return ;
	while (current)
	{
		printf("%d --> argv=", i);
		printf_tab(current->argv);
		if (!current->infile)
			printf("infile=0 ");
		else
			printf("infile=%s ", current->infile);
		if (!current->outfile)
			printf("outfile=0 ");
		else
			printf("outfile=%s ", current->outfile);
		if (!cmd->here_doc_delim)
			printf("doc_delim=0 ");
		else
			printf("doc_delim=%s ", current->here_doc_delim);
		printf("append=%d\n", current->append);
		current = current->next;
		i++;
	}
}
