/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:57:25 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 14:24:49 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Outputs the string 's' to the standard output.
** @param	s	The string to output.
** @return	none
*/
void	ft_putstr(char *s)
{
	ft_putstr_fd(s, STDOUT_FILENO);
}
