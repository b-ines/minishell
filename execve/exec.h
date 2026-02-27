/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:24:18 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/27 12:04:56 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <sys/wait.h>
# include "../lexer/lexer.h"
# include "../builtins/builtins.h"

void	exec(t_terminal *term);
char	*search_cmd(t_terminal *term, char *cmd);
void	print_args(char **args);
#endif
