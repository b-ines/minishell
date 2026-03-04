NAME = minishell
MAKEFLAGS += --no-print-directory
CFLAGS = -Wall -Werror -Wextra -g3 -O0
DEPENDENCIES = -lreadline -lncurses
CFILES = main/main.c main/signals.c main/early_parser.c main/terminal_init.c \
	expand/expand.c expand/expand_type.c expand/expand_utils.c expand/retokenize.c \
	lexer/lexer.c lexer/token_lists.c lexer/debug.c lexer/tokenisation.c lexer/tokenisation_utils.c \
	parser/syntax_check_utils.c parser/syntax_check.c parser/syntax_check_redir.c parser/cmd_list.c parser/debug_cmd.c parser/parser_utils.c parser/parser.c \
	builtins/builtins.c builtins/run_env_unset.c builtins/run_echo_pwd.c builtins/run_exit.c \
	builtins/builtins_utils.c builtins/run_cd.c builtins/env_utils.c builtins/run_export.c builtins/print_sorted_env.c \
	execve/exec.c execve/path.c execve/redirections.c \
	heredoc/heredoc.c heredoc/heredoc_expand.c
INCLUDES = -Ilexer
LIBFT = libft/libft.a
OBJ = $(CFILES:.c=.o)
LB = '\033[38;5;212m'
RST = '\033[0m'

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	@echo $(LB)[[ 💻 Compiling...]]
	@cc $(CFLAGS) $(INCLUDES) $(OBJ) -Llibft -lft -o $(NAME) $(DEPENDENCIES)
	@echo $(LB) $(CAT)
	@echo $(LB)[[ Done 💻 ]] $(RST)

.o:.c
	cc $(CLFAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	@make -C libft

clean:
	@echo $(LB)[[ Clean 💻 ]] $(RST)
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

rec: $(NAME) clean $(LIBFT)

.PHONY: all clean fclean re


CAT=\
"⣿⣿⣿⡟⠁⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⣿⣿⠏⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⣿⡏⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠛⠛⠉⠁⠀⠀⠀⢈\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣿\n"\
"⠀⠀⠀⢸⣿⢁⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠘⢿⣾⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣶⡆⣶⣦⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣿⠿⠃⠀⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣿⣛⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⣀⣴⡼⣷⣝⢾⣭⣻⢿⣷⣾⣿⣿⣿⣿⣿⣿⣿\n"\
"⠀⠀⣠⣾⣿⣿⣷⣶⣶⣾⣿⣿⣿⣿⣷⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
"⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"
