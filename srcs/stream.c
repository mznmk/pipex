/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:31:32 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 13:46:23 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	open_read_fd(t_vars *v)
{
	int	fd;

	if (ft_strncmp(v->r_mode, "read", 4) == 0)
		fd = open(v->argv[v->infile_index],
					O_RDONLY,
					S_IRWXU | S_IRWXG | S_IRWXO);
	return (fd);
}

int	open_write_fd(t_vars *v)
{
	int	fd;

	if (ft_strncmp(v->w_mode, "write", 5) == 0)
		fd = open(v->argv[v->outfile_index],
					O_WRONLY | O_CREAT | O_TRUNC,
					S_IRWXU | S_IRWXG | S_IRWXO);
	else if (ft_strncmp(v->r_mode, "append", 6) == 0)
		fd = open(v->argv[v->outfile_index],
					O_WRONLY | O_CREAT | O_APPEND,
					S_IRWXU | S_IRWXG | S_IRWXO);
	return (fd);
}

void	close_fd(int fd)
{
	int status;

	status = close(fd);
	if (status == -1)
		exit_pipex(EXIT_FAILURE);
}

void
read_stream(t_vars *v)
{
	int		fd_read;

	fd_read = open_read_fd(v);
	if (fd_read == -1)
		exit_pipex(EXIT_FAILURE);
	close(STDIN_FILENO);
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
}

void
write_stream(t_vars *v, int cmd_num)
{
	int		fd_write;

	fd_write = open_write_fd(v);
	if (fd_write == -1)
		exit_pipex(EXIT_FAILURE);
	close(STDOUT_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write);
	if (v->cmd_count == 0)
		exec_command(v->envp, "cat");
	else
		exec_command(v->envp, v->argv[v->cmd_start + cmd_num]);
}
