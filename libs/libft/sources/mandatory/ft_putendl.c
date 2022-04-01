/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:57:13 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 14:24:59 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Outputs the string 's' to the standard output.
** @param	s	The string to output.
** @return	none
*/
void	ft_putendl(char *s)
{
	ft_putendl_fd(s, STDOUT_FILENO);
}
