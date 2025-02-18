#include "../inc/minishell.h"

/*
** Here, we initialized every part of our structures,
** with strings, it will be useful when we will want to compare 
** them. Also, check of the e_nodes in the .h, we will use it
** too, also with the AST. 
*/
void	ft_init_commands(t_commands *commands)
{
	if (!commands)
		return (NULL);
	ft_strcpy(commands->echo, "echo");
	ft_strcpy(commands->cd, "cd");
	ft_strcpy(commands->pwd, "pwd");
	ft_strcpy(commands->export, "export");
	ft_strcpy(commands->unset, "unset");
	ft_strcpy(commands->env, "env");
	ft_strcpy(commands->exit, "exit");
}