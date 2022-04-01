/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:43:09 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 16:15:05 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Outputs the character 'c' to the given file descriptor.
** @param	c: The character to output.
** @param	fd: The file descriptor on which to write.
** @return	none
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
