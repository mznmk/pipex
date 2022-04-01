/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_pipe2_cmd3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 06:11:13 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/01 20:53:20 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

static void
exec_comand(int cmd_cnt, int cmd_num)
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

static void
child_process(int *fd, int cmd_cnt, int cmd_num)
{
	// [ set "child-side" stream ]
	// set stream: upstream-end
	close(fd[0]);
	// set stream: downstream-end
	close(STDOUT_FILENO);
	dup2(fd[1], STDOUT_FILENO);

	// [ execute command ]
	exec_comand(cmd_cnt, cmd_num);
}

static void
parent_process(int *fd)
{
	// [ set "parent-side" stream ]
	// set stream: upstream-end
	close(STDIN_FILENO);
	dup2(fd[0], STDIN_FILENO);
	// set stream: downstream-end
	close(fd[1]);
}

static void
set_read_stream(char **argv)
{
	int		fd_read;

	// [ set stream ]
	// open file
	fd_read = open(argv[1], O_RDONLY,
							S_IRWXU | S_IRWXG | S_IRWXO);
	// set stream: upstream-end
	close(STDIN_FILENO);
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
}

static void
set_write_stream(char **argv, int cmd_cnt, int cmd_num)
{
	int		fd_write;

	// [ set stream ]
	// open file
	fd_write = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
								S_IRWXU | S_IRWXG | S_IRWXO);
	// set stream: downstream-end
	close(STDOUT_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write);

	// [ execute command ]
	exec_comand(cmd_cnt, cmd_num);
}

/*!
** @brief	main (entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	status
*/
int
main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int		cmd_cnt;
	int		cmd_num;

	(void)envp;

	// [ check arguments ]
	if (argc != 3)
		return (1);

	// [ declear const variable ]
	// preset command count (1/2/3/4/5/6)
	cmd_cnt = 6;

	// [ execute command ]
	// set stream (read stream)
	set_read_stream(argv);
	// execute command (0 <= cmd_num < cmd_cnt-1)
	cmd_num = 0;
	for (; cmd_num < cmd_cnt - 1; cmd_num++)
	{
		// create pipe
		pipe(fd);

		// fork process
		pid = fork();
		if (0 == pid)
		{
			// set stream (upstream-end)
			// & execute command (0 <= cmd_num < cmd_cnt-1)
			child_process(fd, cmd_cnt, cmd_num);
		}
		else if (0 < pid)
		{
			// set stream (downstream-end)
			waitpid(pid, NULL, 0);
			parent_process(fd);
		}
	}
	// set stream (write stream)
	// & execute command (cmd_num == cmd_cnt-1)
	set_write_stream(argv, cmd_cnt, cmd_num);

	// [ return ]
	return (0);
}
