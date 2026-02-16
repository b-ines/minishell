#include "../lexer/lexer.h"
#include "../parser/parser.h"

void    program(char *line)
{
    t_token *token;
    
    token = 0;
    token = lexer(line);
    if (!token)
        return ;
    parser(&token);
    printf_list(&token);
}

int main(int argc, char **argv)
{
    char    *line;
    (void)argv;

    if (argc != 1)
        return (0);
    while (1)
    {
        line = readline("minishell$ ");
        if (!line)
            break ;
        rl_on_new_line();
        add_history(line);
        if (!ft_strncmp(line, "", 1))
            continue ;
        program(line);
        if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
            break ;
        free(line);
    }
    return (0);
}
