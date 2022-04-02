/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:05 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 18:35:08 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	exit_pipex(int exit_status)
{
	perror(FNT_BOLD CLR_PINK "ERROR" ESC_RESET);
	exit(exit_status);
}

static void	child_process(t_vars *v, int *fd, int cmd_num)
{
	close_fd(fd[0]);
	close_fd(STDOUT_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	exec_command(v->envp, v->argv[v->cmd_start + cmd_num]);
}

static void	parent_process(int *fd, pid_t pid)
{
	waitpid(pid, NULL, 0);
	close_fd(STDIN_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close_fd(fd[1]);
}

/*!
** @brief	main (mandatory entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	none
*/
void	exec_pipex(t_vars *v)
{
	int		fd[2];
	pid_t	pid;
	int		cmd_num;

	if (ft_strncmp(v->r_mode, "read", 4) == 0)
		read_from_file(v);
	else if (ft_strncmp(v->r_mode, "here_doc", 8) == 0)
		read_from_heredoc(v, fd);
	cmd_num = 0;
	while (cmd_num < v->cmd_count - 1)
	{
		if (pipe(fd) == -1)
			exit_pipex(EXIT_FAILURE);
		pid = fork();
		if (0 == pid)
			child_process(v, fd, cmd_num);
		else if (0 < pid)
			parent_process(fd, pid);
		else
			exit_pipex(EXIT_FAILURE);
		cmd_num++;
	}
	write_into_file(v, cmd_num);
}
