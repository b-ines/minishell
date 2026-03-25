*This project has been created as part of the 42 curriculum by gchalmel, inbeaumo.*  


&nbsp; 

# Description

This project replicates the behavior of a shell. Bash posix was used a the main reference.
The following is handled : 
- double and single quotes when used correctly 
- redirections (> writes on a file, < reads from an existing file, >> writes a file and appends its content, >> mimics a heredoc)
- pipes
- environment variables and error code with $
- ctrl-C ctrl-D and ctrl-\ signals
- the following builtins : echo with -n, cd, pwd, export, unset, env, exit

&nbsp; 
# Instructions

The command ```make``` creates the executable and ``` ./minishell ``` launches the program. The command ```make rec``` creates the program and delete the ```.o``` files.

In order to run valgrind, you can create a document named readline.supp and paste the following content : 
```
{
   readline_reachable
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   obj:*libreadline.so*
}
```
You can then use ```  valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ``` . This will ensure to mask the readline leaks.

&nbsp; 
# Resources

### Links

https://medium.com/@dkwok94/how-a-shell-works-what-happens-when-ls-l-is-typed-df4eb468a030 - how a the shell interprets the command "ls -l"

https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218 - the different steps of the project and errors to avoid from someone who made minishell

https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html - detailed description of shell syntax

https://trove.assistants.epita.fr/docs/42sh/guide/shell_architecture/ - the big steps of the project

https://docs.google.com/spreadsheets/d/1Wqn1l59a4XW5Jk2lhy_BTMR_lHyQ32DnwK5-LsOYIiI/edit?pli=1&gid=0#gid=0 - a list of 800 inputs and the expected output and error code

### AI Usage

AI was used to : 
- understand better the internal process of the shell when testing was not clear
- explain segfaults when the origin couldn't be found
- create the temp.supp to skip readline leaks in valgrind
