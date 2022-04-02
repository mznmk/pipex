/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:31:32 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 18:29:19 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static void	read_from_heredoc_helper(char *limiter)
{
	char	*readline;
	size_t	len;

	len = ft_strlen(limiter);
	while (42)
	{
		readline = get_next_line(STDIN_FILENO);
		if (ft_strncmp(readline, limiter, len) == 0)
		{
			free(readline);
			readline = NULL;
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(readline, STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		free(readline);
		readline = NULL;
	}
}

void	read_from_heredoc(t_vars *v, int *fd)
{
	pid_t	pid;

	if (pipe(fd) == -1)
		exit_pipex(EXIT_FAILURE);
	pid = fork();
	if (0 == pid)
	{
		close_fd(fd[0]);
		close_fd(STDOUT_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		read_from_heredoc_helper(v->limiter);
	}
	else if (0 < pid)
	{
		waitpid(pid, NULL, 0);
		close_fd(STDIN_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close_fd(fd[1]);
	}
	else
		exit_pipex(EXIT_FAILURE);
}

void	read_from_file(t_vars *v)
{
	int		fd_read;

	fd_read = open_read_fd(v);
	if (fd_read == -1)
		exit_pipex(EXIT_FAILURE);
	close_fd(STDIN_FILENO);
	dup2(fd_read, STDIN_FILENO);
	close_fd(fd_read);
}

void	write_into_file(t_vars *v, int cmd_num)
{
	int		fd_write;

	fd_write = open_write_fd(v);
	if (fd_write == -1)
		exit_pipex(EXIT_FAILURE);
	close_fd(STDOUT_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close_fd(fd_write);
	if (v->cmd_count == 0)
		exec_command(v->envp, "cat");
	else
		exec_command(v->envp, v->argv[v->cmd_start + cmd_num]);
}
