/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 06:26:48 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 14:07:39 by mmizuno          ###   ########.fr       */
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
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		v->r_mode = "here_doc";
		v->w_mode = "append";
		v->cmd_count = argc - 4;
		v->cmd_start = 3;
	}
	v->infile_index = 1;
	v->outfile_index = argc - 1;
}

/*!
** @brief	main (bonus entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	status
*/
int	main(int argc, char **argv, char **envp)
{
	t_vars	v;

	if (3 <= argc)
	{
		init_pipex(&v, argc, argv, envp);
		exec_pipex(&v);
	}
	return (0);
}
