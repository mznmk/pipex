/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:28:11 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 06:57:42 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Lexicographical comparison between s1 and s2.
**			If the 2 strings are identical the function returns 1,or 0 therwise.
** @param	s1	The first string to be compared.
** @param	s2	The second string to be compared.
** @return	1 or 0 according to if the 2 strings are identical or not.
*/
int	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
