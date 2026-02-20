#include "builtins.h"

int is_builtins(t_token *token)
{
    if (!ft_strcmp(token->token, "echo"))
        return (1);
    else if (!ft_strcmp(token->token, "cd"))
        return (1);
    else if (!ft_strcmp(token->token, "pwd"))
        return (1);
    else if (!ft_strcmp(token->token, "export"))
        return (1);
    else if (!ft_strcmp(token->token, "unset"))
        return (1);
    else if (!ft_strcmp(token->token, "env"))
        return (1);
    else
        return (0);
}

void    builtins(t_terminal *terminal, t_token **token_head)
{
    t_token *current;

    current = *token_head;
    (void)terminal;
    while (current)
    {
        if (is_builtins(current))
            printf("builtins\n");
        current = current->next;
    }
}