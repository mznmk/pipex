/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_pipe0_cmd1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 06:11:13 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/01 20:53:16 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

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
	int		fd_read;

	(void)envp;

	// [ check arguments ]
	if (argc != 2)
		return (1);

	// [ set stream ]
	// open file: upstream-end
	fd_read = open(argv[1], O_RDONLY,
							S_IRWXU | S_IRWXG | S_IRWXO);
	// set stream: upstream-end
	close(STDIN_FILENO);
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
	// set stream: downstream-end

	// [ execute command ]
	execlp("wc", "wc", "-w", NULL);

	// [ return ]
	return (0);
}
