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

void	execute_ast(t_AST *node, char **envp)
{
	if (!node)
		return ;
	if (node->type == NODE_COMMAND)
		exec_simple_cmd(node, envp);
	if (node->type == NODE_PIPE)
		exec_pipe(node, envp);
	else if (node->type == NODE_REDIR_IN || node->type == NODE_REDIR_OUT || node->type == NODE_REDIR_APPEND)
		exec_redir(node, envp);
}

void	exec_redir(t_AST *node, char **envp)
{
	int	fd;
	int	backup;
	int	std_fd;

	if (!node || !node->filename)
		return ;
	if (node->type == NODE_REDIR_OUT)
		fd = open(node->filename, O_WRONLY, O_CREAT, O_TRUNC, 0664);
	if (node->type == NODE_REDIR_IN)
		fd = open(node->filename, O_WRONLY, O_CREAT, O_APPEND, 0664);
	if (node->type == NODE_REDIR_APPEND)
		fd = open(node->filename, O_RDONLY);
	else
		return ;
	if (fd == -1)
		return (perror("open"));
	std_fd = STDOUT_FILENO;
	if (node->type == NODE_REDIR_IN)
	std_fd = STDIN_FILENO;
	backup = dup(std_fd);
	dup2(fd, std_fd);
	close(fd);
	execute_ast(node->left, envp);
	dup2(backup, std_fd);
	close(backup);
}