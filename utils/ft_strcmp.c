#include "../inc/minishell.h"

int	ft_strcmp(const char *first, const char *second)
{
	int	i;
	while (first[i] == second[i])
	{
		if (second[i] && first[i] != second[i])
			return (1);
		else if (second[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}