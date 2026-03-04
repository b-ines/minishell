/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:20:54 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/04 12:13:55 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

#include "../main/main.h"
#include "../builtins/builtins.h"

//heredoc_expand.c
char	*expand_line(t_terminal *term, char *line);

int		parse_heredoc(t_terminal *term);

#endif