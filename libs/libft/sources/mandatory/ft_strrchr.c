/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:17:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 20:54:57 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	The strchr() function locates the last occurrence of c
**			(converted to a char) in the string pointed to by s.
**			The terminating null character is considered part of the string;
**			therefore if c is `\0', the	functions locate the terminating `\0'.
** @return	strrchr() return a pointer to the located character,
**			or NULL	if the character does not appear in the	string.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*char_s;
	char	*find_ptr;

	char_s = (char *)s;
	find_ptr = NULL;
	i = -1;
	while (char_s[++i])
	{
		if (char_s[i] == (char)c)
			find_ptr = &char_s[i];
	}
	return (find_ptr);
}
