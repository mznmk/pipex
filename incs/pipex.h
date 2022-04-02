/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:28:23 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 18:36:04 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// ================================= const ================================== //

// --------------------------------- color ---------------------------------- //

# define ESC_RESET				"\033[0m"
# define FNT_BOLD				"\033[1m"
# define FNT_FINE				"\033[2m"
# define FNT_ITALIC				"\033[3m"
# define FNT_ULINE				"\033[4m"
# define CLR_BLACK				"\033[38;5;00m"
# define CLR_RED				"\033[38;5;01m"
# define CLR_GREEN				"\033[38;5;02m"
# define CLR_YELLOW				"\033[38;5;03m"
# define CLR_BLUE				"\033[38;5;04m"
# define CLR_MAGENTA			"\033[38;5;05m"
# define CLR_CYAN				"\033[38;5;06m"
# define CLR_WHITE				"\033[38;5;07m"
# define CLR_PINK				"\033[38;5;213m"

// ================================ library ================================= //

# include "../libs/libft/includes/libft.h"
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

// ================================= struct ================================= //

typedef struct s_vars
{
	int			argc;
	char		**argv;
	char		**envp;
	int			cmd_count;
	int			cmd_start;
	int			infile_index;
	int			outfile_index;
	char		*r_mode;
	char		*w_mode;
	char		*limiter;
}				t_vars;

// ========================= prototype declaration ========================== //

// openclose.c
int		open_read_fd(t_vars *v);
int		open_write_fd(t_vars *v);
void	close_fd(int fd);

// stream.c
void	read_from_heredoc(t_vars *v, int *fd);
void	read_from_file(t_vars *v);
void	write_into_file(t_vars *v, int cmd_num);

// execute.c
void	exec_command(char **envp, char *command);

// pipex.c
int		exit_pipex(int exit_status);
void	exec_pipex(t_vars *v);

#endif