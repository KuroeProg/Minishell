#include "minishell.h"

int	e_commands(char *str, t_commands *commands)
{
	int	i;
	int	check;

	i = 0;
	check = 1;
	if (str[i + 1] == 'c')
	{
		check = ft_strcmp(str, commands->echo);
		if (check == 0)
			ft_echo();
	}
	else if (str[i + 1] == 'x')
	{
		if (str[i + 2] == 'p')
		{
			check = ft_strcmp(str, commands->export);
			if (check == 0)
			ft_export();
		}
		else if (str[i + 2] == 'x')
		{
			check = ft_strcmp(str, commands->exit);
			if (check == 0)
			ft_exit();
		}
	}
	else if (str[i + 1] == 'n')
	{
		check = ft_strcmp(str, commands->env);
		if (check == 0)
			ft_env();
	}
	return (check);
}
int	other_commands(char *str, t_commands *commands)
{
	int	check;

	check = 1;
	if (str[0] == 'c')
	{
		check = ft_strcmp(str, commands->cd);
		if (check == 0)
			ft_cd();
	}
	if (str[0] == 'p')
	{
		check = ft_strcmp(str, commands->pwd);
		if (check == 0)
			ft_pwd();
	}
	if (str[0] == 'u')
	{
		check = ft_strcmp(str, commands->unset);
		if (check == 0)
			ft_unset();
	}
	return (check);
}

int		reco_commands(t_AST *ast, t_commands *commands)
{
	int	i;

	i = 0;
	while (ast->argv)
	{
		while (*ast->argv[i])
		{
			while (!ft_isdigit(*ast->argv[i]))
				i++;
			if (*ast->argv[1] == 'e')
				return(e_commands(*ast->argv + i, commands));
			else
				return(other_commands(*ast->argv + i, commands));
			i++;
		}
		ast->argv++;
	}
	return (1);
}