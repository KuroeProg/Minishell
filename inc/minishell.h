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
** A list of every command (who will be initialized)
** in the main. The target here is to check which command
** is writed, by comparing them with a ft_strcmp.
*/
typedef	struct s_commands
{
	char	echo[5];
	char	cd[3];
	char	pwd[4];
	char	export[7];
	char	unset[6];
	char	env[4];
	char	exit[5];
} t_commands;
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

char		*ft_strchr(const char *s, int c);
char		*ft_strtok(char *str, const char *delim, char **ptr_save);
t_commands	*ft_init_commands(t_commands *commands);
char		*ft_strcpy(char *dest, const char *src);

#endif