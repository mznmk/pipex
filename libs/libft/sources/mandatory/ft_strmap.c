/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:40:15 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 00:30:40 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Applies the function 'f' to each character of the string given
**			as argument to create a "fresh" new string (with malloc(3))
**			resulting from successive applications of 'f'.
** @param	s		The string to map.
** @param	(*f)	The function to apply to each character of s.
** @return	The "fresh" string created from the successive applications of 'f'.
**			Returns NULL if the allocation fails.
*/
char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = f(str[i]);
		i++;
	}
	return (str);
}
