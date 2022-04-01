/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 23:08:19 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 19:39:55 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	The memset() function writes len bytes of value c
**			(converted to an unsigned char) to the string dest.
** @return	The memset() function returns its first argument.
*/
void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*uc_dest;
	unsigned char	uc_c;

	uc_dest = (unsigned char *)dest;
	uc_c = (unsigned char)c;
	while (0 < len--)
		*uc_dest++ = uc_c;
	return (dest);
}
