#include "../inc/minishell.h"

char	*ft_strtok(char *str, const char *delim, char **ptr_save)
{

	char	*token_start;

	if (str)
		*ptr_save = str;
	if (!*ptr_save)
		return (NULL);
	while (**ptr_save && ft_strchr(delim, **ptr_save))
		(*ptr_save)++;
	if (**ptr_save == '\0')
	{
		*ptr_save = NULL;
		return (NULL);
	}
	token_start = *ptr_save;
	while (**ptr_save && !ft_strchr(delim, **ptr_save))
		(*ptr_save)++;
	if (**ptr_save)
	{
		**ptr_save = '\0';
		(*ptr_save)++;
	}
	else
		*ptr_save = NULL;
	return (token_start);
}
