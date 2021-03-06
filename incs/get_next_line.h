/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:01:37 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/02 16:54:03 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ================================= const ================================== //

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif
# ifndef FD_MAX
#  define FD_MAX		1024
# endif
# define FD_NOTUSE		2

// ================================ library ================================= //

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

// ========================= prototype declaration ========================== //

// get_next_line_util.c
char	*gnl_allocate_memory(int size);
char	*gnl_deallocate_memory(char **memory);
long	gnl_strlen(const char *s);
char	*gnl_substr(char *s, long start, long len);
long	find_index(const char *s, char c);

// get_next_line.c
char	*get_next_line(int fd);

#endif