#ifndef MAIN_H
# define MAIN_H

# include "../lexer/lexer.h"
# include "../parser/parser.h"
# include "../expand/expand.h"
# include "../builtins/builtins.h"
# include <signal.h>

typedef struct s_terminal {
    int terminal_status;
}   t_terminal;

#endif