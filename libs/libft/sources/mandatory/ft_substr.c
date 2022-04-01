/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:42:02 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 01:05:04 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Allocates (with malloc(3)) and returns a "fresh" substring
**			from the string given as argument.
**			The substring begins at index 'start' and is of maximum size len.
**			If start and len arn't refering to valid substring, the behavor is
**			undefined. If the allocation fails, the function returns NULL.
** @param	s		The string from which to create the substring.
** @param	start	The start index of the substring in the string 's'.
** @param	len		The maximum length of the substring.
** @return	The substring. NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if ((s_len == 0) || (s_len < (size_t)start))
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
