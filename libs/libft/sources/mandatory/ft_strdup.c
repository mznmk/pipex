/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:23:05 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 20:15:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	The strdup() function allocates sufficient memory for a copy
**			of the string str, does the copy, and returns a pointer to it.
**			The pointer may subsequently be used as an argument
**			to the function free(3).
**			If insufficient memory is available,
**			NULL is returned and errno is set to ENOMEM.
** @return	duplicated string pointer.
*/
char	*ft_strdup(const char *s)
{
	char			*dest;
	unsigned long	len;

	len = ft_strlen((char *)s);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}
