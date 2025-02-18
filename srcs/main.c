#include "../inc/minishell.h"

int	main(int argc, char **argv)
{
	t_commands	commands;
	t_AST		ast;

	ft_init_commands(&commands);
	ast.argv = argv;
	if (!reco_commands(&ast, &commands));
		error();
}