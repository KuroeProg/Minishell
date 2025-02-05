#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
/*
** We are creating an Enum for each signs.
*/
typedef enum
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIRECT,
	NODE_SEQUENCE,
	NODE_AND,
	NODE_OR,
} e_nodes;

/*
** type -> will be a value from our enum e_nodes
** *right and *left are pointer to an other node
** **argv will takes the arguments ('ls' '-l' 'NULL')
** *filename is the PATH of the redirection file
** append is here to indicate if it's a > or a >>
** 0 for >, 1 for >>
*/

typedef struct	s_AST
{
	e_nodes	type;
	struct AST	*right;
	struct AST	*left;
	char	**argv;
	char	*filename;
	int		append;
}		t_AST;

char	*ft_strchr(const char *s, int c);
char	*ft_strtok(char *str, const char *delim, char **ptr_save);

#endif