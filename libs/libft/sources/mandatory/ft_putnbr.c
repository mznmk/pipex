/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:57:20 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 14:14:07 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Outputs the integer 'n' to the standard output.
** @param	n	The integer to output.
** @return	none
*/
void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, STDOUT_FILENO);
}
