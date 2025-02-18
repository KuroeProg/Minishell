#include "../inc/minishell.h"

void	exec_simple_cmd(t_AST *node, char **envp)
{
	pid_t		pid;
	
	pid = fork();
	if (pid == 0)
	{
		if (execve(node->argv[0], node->argv, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork");
}

void	exec_pipe(t_AST *node, char **envp)
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		return (perror("pipe"));
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_ast(node->left, envp);
		exit(EXIT_SUCCESS);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execute_ast(node->right, envp);
		exit(EXIT_SUCCESS);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}