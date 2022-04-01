/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:57:05 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 15:58:39 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Outputs the character 'c' to the standard output.
** @param	c	The character to output.
** @return	none
*/
void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}
