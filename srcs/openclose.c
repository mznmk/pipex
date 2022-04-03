/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:31:32 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/03 21:56:16 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	open_read_fd(t_vars *v)
{
	int	fd;

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
	else if (ft_strncmp(v->w_mode, "append", 6) == 0)
		fd = open(v->argv[v->outfile_index],
				O_WRONLY | O_CREAT | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
	return (fd);
}

void	close_fd(int fd)
{
	int	status;

	status = close(fd);
	if (status == -1)
		exit_pipex(EXIT_FAILURE);
}
