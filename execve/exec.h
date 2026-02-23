/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:18 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/23 17:14:50 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/wait.h>
# include "../lexer/lexer.h"

void	exec(t_terminal *term);
char	*search_cmd(char *cmd);
void	print_args(char **args);
#endif
