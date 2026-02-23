#include "builtins.h"

//en vrai faire un printf_fd cest plus facile quand meme

void    run_cd(t_terminal *terminal, t_cmd *cmd)
{
	if (tab_size(cmd) > 2)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(cmd->argv[1], 1);
		ft_putstr_fd(": too many arguments", 2);
		terminal->exit_status = 1;
		return ; // ou juste else if
	}
	if (cmd->argv[1])
	{
		printf("%s\n", get_value_by_key(terminal, cmd->argv[1]));
		if (chdir(cmd->argv[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 1);
		}
	}
}