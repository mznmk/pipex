/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:17:52 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/12 20:39:41 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*!
** @brief	strlcat() appends string src to the end of dst.
**			It will append at most dstsize - strlen(dst) - 1 characters.
**			It will then NUL-terminate,
**			unless dstsize is 0 or the original dst string was longer
**			than dstsize (in practice this should not happen as it means that
**			either dstsize is incorrect or that dst is not a proper string).
** @return	strlcat() functions return
**			the total length of the string they tried to create.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ul_dst_len;
	size_t	ul_src_len;

	ul_dst_len = ft_strlen((char *)dst);
	ul_src_len = ft_strlen((char *)src);
	if (dstsize <= ul_dst_len)
		return (dstsize + ul_src_len);
	i = 0;
	while (src[i] && (ul_dst_len + i < dstsize - 1))
	{
		dst[ul_dst_len + i] = src[i];
		i++;
	}
	dst[ul_dst_len + i] = '\0';
	return (ul_dst_len + ul_src_len);
}
