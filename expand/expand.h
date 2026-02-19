/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabch <gabch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:39:40 by gchalmel          #+#    #+#             */
/*   Updated: 2026/02/19 21:16:37 by gabch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "../lexer/lexer.h"

typedef enum e_expand_type
{
	ENV,
	ONE_DOLLARS,
	EXIT_STATUS,
	ENV_PLUS_ONE_DOLLARS,
}	t_expand_type;

void expand(t_token *token);

#endif
