/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:10:04 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 13:21:22 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	len;

	dst_len = 0;
	if (dst)
		dst_len = ft_strlen(dst);
	len = ft_strlen(src) + dst_len;
	j = dst_len;
	i = 0;
	if (dstsize == 0 && !dst)
		return (0);
	if (j >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < (dstsize - dst_len - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len);
}
