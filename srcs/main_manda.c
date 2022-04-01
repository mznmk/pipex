/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_manda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:51:01 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/01 18:49:17 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/pipex.h"

/*!
** @brief	main (mandatory entry point)
** @param	argc	argument count
** @param	argv	argument variables
** @param	envp	environment variables
** @return	status
*/
int
main(int argc, char **argv, char **envp)
{
	char	*w_mode;
	int		cmd_cnt;
	int		status;

	if (5 == argc)
	{
		w_mode = "write";
		cmd_cnt = argc - 3;
		status = exec_pipex(argc, argv, envp, w_mode, cmd_cnt);
		return (status);
	}

	return (0);
}