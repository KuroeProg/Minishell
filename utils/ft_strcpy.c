#include "../inc/minishell.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}