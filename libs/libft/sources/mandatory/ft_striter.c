/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:18:57 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 23:31:54 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	Applies the function f to each character of the string passed
**			as argument.
**			Each character is passed by address to f to be modified
**			if necessary.
** @param	s	The string to iterate
** @param	f	The function to apply to each character of s.
** @return	None.
*/
void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
	{
		f(s);
		s++;
	}
}
