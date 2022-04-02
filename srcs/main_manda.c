/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:51:01 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 14:08:42 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*!
** @brief	init pipex data struct
** @param	v		pipex data struct
*/
static void	init_pipex(t_vars *v, int argc, char **argv, char **envp)
{
	v->argc = argc;
	v->argv = argv;
	v->envp = envp;
	v->r_mode = "read";
	v->w_mode = "write";
	v->cmd_count = argc - 3;
	v->cmd_start = 2;
	v->infile_index = 1;
	v->outfile_index = argc - 1;
}

/*!
** @brief	main (mandatory entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	status
*/
int	main(int argc, char **argv, char **envp)
{
	t_vars	v;

	if (5 == argc)
	{
		init_pipex(&v, argc, argv, envp);
		exec_pipex(&v);
	}
	return (0);
}
