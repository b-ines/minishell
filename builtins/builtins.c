#include "builtins.h"

int is_builtins(t_token *token)
{
    if (!ft_strncmp(token->token, "echo", ft_strlen(token->token)))
        return (1);
    if (!ft_strncmp(token->token, "cd", ft_strlen(token->token)))
        return (1);
    if (!ft_strncmp(token->token, "pwd", ft_strlen(token->token)))
        return (1);
    if (!ft_strncmp(token->token, "export", ft_strlen(token->token)))
        return (1);
    if (!ft_strncmp(token->token, "unset", ft_strlen(token->token)))
        return (1);
    if (!ft_strncmp(token->token, "env", ft_strlen(token->token)))
        return (1);
    return (0);
}

void    builtins(t_token **token_head)
{
    t_token *current;

    current = *token_head;
    while (current)
    {
        if (is_builtins(current))
            printf("cest un builtins!!\n");
        current = current->next;
    }
}