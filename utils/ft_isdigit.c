#include "minishell.h"

int	ft_isdigit(char c)
{
	int	i;

	i = 0;
	if (c > 'a' && c < 'z' || c > 'A' && c < 'Z')
		return (1);
	return (0);
}