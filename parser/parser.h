#ifndef PARSER_H
# define PARSER_H

# include "../lexer/lexer.h"

int valid_syntax(t_terminal *terminal, t_token **token_head);
t_cmd	*parser(t_terminal *terminal, t_token *token);

//cmd_lists.c
t_cmd *create_node_cmd(void);
void    ft_addback_cmd(t_cmd **cmd_head, t_cmd *new_node);

//debug
void    printf_tab(char **tab);
void printf_cmd(t_cmd *cmd);

#endif