/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:57:53 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 07:02:54 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Lexicographical comparison between s1 and s2 up to c characters
**			or until a '\0' is reached.
**			If the 2 strings are identical the function returns 1,or 0 therwise.
** @param	s1	The first string to be compared.
** @param	s2	The second string to be compared.
** @param	n	The maximum number of characters to be compared.
** @return	1 or 0 according to if the 2 strings are identical or not.
*/
int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
