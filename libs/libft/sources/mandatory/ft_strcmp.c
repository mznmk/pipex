/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:41:05 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 21:09:56 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	strcmp() functions lexicographically compare
**			the nullterminated strings s1 and s2.
** @return	strcmp() functions return an integer greater than, equal to,
**			or less than 0, according as the string s1 is greater than,
**			equal to, or less than the string s2.
**			The comparison is done using un signed characters,
**			so that `\200' is greater than '\0'.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
