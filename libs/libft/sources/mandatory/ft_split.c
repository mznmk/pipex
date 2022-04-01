/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 01:38:32 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 13:04:52 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_dest(char const *str, char delimiter)
{
	int		i;
	int		dest_count;

	dest_count = 0;
	if (str[0] != delimiter)
		dest_count++;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] == delimiter && str[i] != delimiter)
			dest_count++;
		i++;
	}
	return (dest_count);
}

static void	malloc_free(char **dests)
{
	int		i;

	i = -1;
	while (dests[++i])
		free(dests[i]);
	free(dests);
}

static char	**create_dests(char const *s, char c, char **dests)
{
	size_t		src_pos;
	int			dest_len;
	int			i;

	src_pos = -1;
	i = 0;
	while (++src_pos < ft_strlen((char *)s))
	{
		dest_len = 0;
		while (s[src_pos + dest_len] && s[src_pos + dest_len] != c)
			dest_len++;
		if (dest_len)
		{
			dests[i] = ft_substr(s, (unsigned int)src_pos, dest_len);
			if (!dests[i])
			{
				malloc_free(dests);
				return (NULL);
			}
			i++;
			src_pos = src_pos + dest_len;
		}
	}
	dests[i] = (char *)0;
	return (dests);
}

/*!
** @brief	Allocates (with malloc(3)) and returns an array of "fresh" strings
**			obtained by splitting 's' using the character 'c' as a delimiter.
**			The array must be ended by a NULL pointer.
** @param	s	The string to be split.
** @param	c	The delimiter character.
** @return	The array of "fresh" strings result of the split.
**			NULL if the allocation fails.
*/
char	**ft_split(char const *s, char c)
{
	char	**dests;
	int		dests_len;

	if (!s)
		return (NULL);
	dests_len = count_dest(s, c);
	dests = (char **)malloc(sizeof(char *) * (dests_len + 1));
	if (!dests)
		return (NULL);
	dests = create_dests(s, c, dests);
	return (dests);
}
