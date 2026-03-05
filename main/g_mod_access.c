#include "main.h"

static t_gmod g_mod;

void	init_gmod()
{
	g_mod = PROMPT;
}

void	set_gmod(t_gmod new_mode)
{
	g_mod = new_mode;
}

t_gmod	get_gmod()
{
	return (g_mod);
}
