/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:31:32 by mmizuno           #+#    #+#             */
/*   Updated: 2022/03/31 20:52:24 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

int	open_fd(char *path, const char *mode)
{
	int	fd;

	if (ft_strncmp(mode, "read", 4) == 0)
		fd = open(path, O_RDONLY,
						S_IRWXU | S_IRWXG | S_IRWXO);
	else if (ft_strncmp(mode, "write", 5) == 0)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC,
						S_IRWXU | S_IRWXG | S_IRWXO);
	else if (ft_strncmp(mode, "append", 6) == 0)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND,
						S_IRWXU | S_IRWXG | S_IRWXO);

	return (fd);
}

