#include "main.h"

t_terminal *get_term()
{
	static t_terminal term;
	return (&term);
}
