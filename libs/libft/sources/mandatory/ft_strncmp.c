/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:17:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 01:22:57 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	strncmp() functions lexicographically compare
**			the nullterminated strings s1 and s2.
**			strncmp() function compares not more than len characters.
** @return	strncmp() functions return an integer greater than, equal to,
**			or less than 0, according as the string s1 is greater than,
**			equal to, or less than the string s2.
**			The comparison is done using un signed characters,
**			so that `\200' is greater than '\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < len - 1))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
