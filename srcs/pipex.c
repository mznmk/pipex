/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:52:05 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/01 19:24:23 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	exit_pipex(int exit_status)
{
	perror("ERROR");
	exit(exit_status);
}

static void	exec_comand(int cmd_cnt, int cmd_num)
{
	if (cmd_num == cmd_cnt - 1)
		execlp("wc", "wc", "-w", NULL);
	else if (cmd_num == 0)
		execlp("grep", "grep", "aa", NULL);
	else if (cmd_num == 1)
		execlp("grep", "grep", "xx", NULL);
	else if (cmd_num == 2)
		execlp("grep", "grep", "yy", NULL);
	else if (cmd_num == 3)
		execlp("grep", "grep", "zz", NULL);
	else if (cmd_num == 4)
		execlp("grep", "grep", "bb", NULL);
}


static void	child_process(int *fd, int cmd_cnt, int cmd_num)
{
	close(fd[0]);
	close(STDOUT_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	exec_comand(cmd_cnt, cmd_num);
}

static void	parent_process(int *fd)
{
	close(STDIN_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
}

static void	set_read_stream(char **argv)
{
	int		fd_read;

	fd_read = open_fd(argv[1], "read");
	close(STDIN_FILENO);
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
}

static void
set_write_stream(char **argv, char *w_mode, int cmd_cnt, int cmd_num)
{
	int		fd_write;

	fd_write = open_fd(argv[4], w_mode);
	close(STDOUT_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write);
	exec_comand(cmd_cnt, cmd_num);
}


/*!
** @brief	main (mandatory entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	status
*/
int	exec_pipex(int argc, char **argv, char **envp, char *w_mode, int cmd_cnt)
{
	int		fd[2];
	pid_t	pid;
	int		cmd_num;

	(void)argc;
	(void)envp;

	set_read_stream(argv);
	cmd_num = 0;
	while (cmd_num < cmd_cnt - 1)
	{
		pipe(fd);
		pid = fork();
		if (0 == pid)
			child_process(fd, cmd_cnt, cmd_num);
		else if (0 < pid)
		{
			waitpid(pid, NULL, 0);
			parent_process(fd);
		}
		else
			exit_pipex(EXIT_FAILURE);
		cmd_num++;
	}
	set_write_stream(argv, w_mode, cmd_cnt, cmd_num);
	return (0);
}