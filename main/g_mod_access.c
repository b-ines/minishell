/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mod_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbeaumo <inbeaumo@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:07:03 by inbeaumo          #+#    #+#             */
/*   Updated: 2026/03/11 18:07:05 by inbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_gmod	g_mod;

void	init_gmod(void)
{
	g_mod = PROMPT;
}

void	set_gmod(t_gmod new_mode)
{
	g_mod = new_mode;
}

t_gmod	get_gmod(void)
{
	return (g_mod);
}
