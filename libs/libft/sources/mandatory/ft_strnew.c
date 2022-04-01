/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:48:53 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 22:56:47 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Allocates (with malloc(3)) and returns a "fresh" string ending
**			with '\0'. Each character of the string is initialized at '0'.
**			If the allocation fails the function returns NULL.
** @param	size	The size of the string to be allocated.
** @return	The string allocated and initialized to 0.
*/
char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
