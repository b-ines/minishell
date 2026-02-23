#include "builtins.h"

int	get_index_by_key(t_terminal *terminal, char *key)
{
	int	i;

	i = 0;
	while (terminal->envp[i])
	{
		if (!ft_strncmp(terminal->envp[i], key, ft_strlen(key)) && terminal->envp[i][ft_strlen(key)] == '=')	
			return (i);
		i++;
	}
	return (-1);
}

char	*get_value_by_key(t_terminal *terminal, char *key)
{
	(void)terminal;
	int	i;
	char	*value;

	i = get_index_by_key(terminal, key);
	
	printf("key %s i %d \n", key, i);
	if (i == -1)
		return (0);
	value = ft_strchr(terminal->envp[i], '=');
	if (!value)
		return (0);
	return (value + 1);
}

