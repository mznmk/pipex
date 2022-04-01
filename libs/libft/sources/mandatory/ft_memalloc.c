/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 22:15:29 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 22:24:13 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Allocates (with malloc(3)) and returns a "fresh" memory area.
**			The memory allocated is initialized to 0.
**			If the allocation fails, the function returns NULL.
** @param	size	The size of the memory that needs to be allocated.
** @return	The allocated memory area.
*/
void	*ft_memalloc(size_t size)
{
	void	*memory;

	if (!size)
		return (NULL);
	memory = (void *)malloc(sizeof(void) * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, size);
	return (memory);
}
