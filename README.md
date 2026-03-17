*This project has been created as part of the 42 curriculum by gchalmel, inbeaumo.*

TEMP CHERCHER SUR OBISIDIAN POUR RESSOURCES ET PARLER PLUS

# Description

This project replicates the behavior of a bash terminal. 
Bash 

# Instructions

You can use make to create the executable minishell and run ``` ./minishell ``` in the terminal. Additional arameters are not accepted.

In order to run valgrind, you should create a document named readline.supp with this content : 
```
{
   readline_reachable
   Memcheck:Leak
   match-leak-kinds: reachable
   ...
   obj:*libreadline.so*
}
```
You can then use ```  valgrind --trace-children=yes --leak-check=full --show-leak-kinds=all --suppressions=temp.supp ``` . This will ensure to mask the readline leaks.

# Resources

### Links
https://medium.com/@gibrat.dylan/minishell-42-lart-de-cr%C3%A9er-un-shell-performant-et-maintenable-53c0aede140e
### AI Usage
