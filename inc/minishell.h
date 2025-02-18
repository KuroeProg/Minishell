#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

/*
** We are creating an Enum for each signs.
*/
typedef enum
{
	NODE_COMMAND, //simples commands 'ls -l'
	NODE_PIPE, //Operator '|'
	NODE_AND, //Operator '&&'
	NODE_OR, //Operator '||'
	NODE_REDIR_IN, //'<' 
	NODE_REDIR_OUT, // '>'
	NODE_REDIR_APPEND // '>>'
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
	struct s_AST	*right;
	struct s_AST	*left;
	char	**argv;
	char	*filename;
	int		append; //1 if ">>", else 0
}		t_AST;

/*
** AST functions.
*/

t_AST	*create_node(e_nodes type, char **argv, char *filename, int append);
void	free_ast(t_AST *node);

/*
** debug for the ast
*/
void	print_ast(t_AST *node, int level);
void	execute_ast(t_AST *node);

/*
** Utils.
*/
char		*ft_strchr(const char *s, int c);
char		*ft_strtok(char *str, const char *delim, char **ptr_save);
void		ft_init_commands(t_commands *commands);
char		*ft_strcpy(char *dest, const char *src);
int			ft_isdigit(char c);
int			ft_strcmp(const char *first, const char *second);

int			reco_commands(t_AST *ast, t_commands *commands);
int			e_commands(char *str, t_commands *commands);
int			other_commands(char *str, t_commands *commands);

#endif