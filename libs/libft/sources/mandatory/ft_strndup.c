/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:23:05 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 20:24:30 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	The ft_strdup() function allocates sufficient memory to copy n bytes
**			of the string s, does the copy, and returns a pointer to it.
**			The pointer may subsequently be used as an argument to the function
**			free(3). If insufficient memory is available,
**			NULL is returned and errno is set to ENOMEM.
** @return	duplicated string pointer.
*/
char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, n + 1);
	return (dest);
}
