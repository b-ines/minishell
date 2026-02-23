#ifndef BUILTINS_H
# define BUILTINS_H

#include "../main/main.h"
#include <fcntl.h>

void    builtins(t_terminal *terminal);

//run_builtins.c
void    run_echo(t_terminal *terminal, t_cmd *cmd, int fd);
void    run_exit(t_terminal *terminal, t_cmd *cmd);
void    run_pwd(t_terminal *terminal, t_cmd *cmd, int fd);

//utils.c
int	    get_fd(t_cmd *cmd);
int	    tab_size(char **argv);

//runenv
void    run_env(t_terminal *terminal, t_cmd *cmd, int fd);
void    run_unset(t_terminal *terminal, t_cmd *cmd);

//env_management.c
int	get_index_by_key(t_terminal *terminal, char *key);
char	*get_value_by_key(t_terminal *terminal, char *key);

void    run_cd(t_terminal *terminal, t_cmd *cmd);


#endif