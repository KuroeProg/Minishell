#include "../inc/minishell.h"

t_AST *create_node(e_nodes type, char **argv, char *filename, int append)
{
	t_AST	*node;

	node = malloc(sizeof(t_AST));
	if (!node)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	node->type = type;
	node->argv = argv;
	node->filename = filename;
	node->append = append;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	free_ast(t_AST *node)
{
	int	i;

	i = 0;
	if (!node)
		return ;
	if (node->argv)
	{
		while (node->argv[i] != NULL)
			free(node->argv[i++]);
		free(node->argv);
	}
	if (node->filename)
		free(node->filename);
	free_ast(node->left);
	free_ast(node->right);
	free(node);
}