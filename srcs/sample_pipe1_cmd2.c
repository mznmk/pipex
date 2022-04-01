/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_pipe1_cmd2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 06:11:13 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/01 11:10:26 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static void	child_process(char **argv, int *fd)
{
	int		fd_read;

	// [ set "child-side" stream ]
	// open file: upstrem-end
	fd_read = open_fd(argv[1], "read");
	// set stream: upstream-end
	close(fd[0]);
	close(STDIN_FILENO);
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
	// set stream: downstream-end
	close(STDOUT_FILENO);
	dup2(fd[1], STDOUT_FILENO);

	// [ execute command ]
	execlp("grep", "grep", "aa", NULL);
}

static void	parent_process(char **argv, int *fd)
{
	int		fd_write;

	// [ set "parent-side" stream ]
	// set stream: upstream-end
	close(STDIN_FILENO);
	dup2(fd[0], STDIN_FILENO);
	// open file: downstream-end
	fd_write = open_fd(argv[2], "write");
	// set stream: downstream-end
	close(fd[1]);
	close(STDOUT_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write);

	// [ execute command ]
	execlp("wc", "wc", "-w", NULL);
}

/*!
** @brief	main (entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	status
*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	(void)envp;

	// [ check arguments ]
	if (argc != 3)
		return (1);

	// [ execute command ]
	// create pipe
	pipe(fd);
	// fork process
	pid = fork();
	if (0 == pid)
	{
		child_process(argv, fd);
	}
	else if (0 < pid)
	{
		waitpid(pid, NULL, 0);
		parent_process(argv, fd);
	}

	// [ return ]
	return (0);
}
