/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:51:35 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/20 19:33:17 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_f;
	char	*src_f;

	dst_f = (char *)dst;
	src_f = (char *)src;
	if (src_f < dst_f)
	{
		while (len > 0)
		{
			len--;
			dst_f[len] = src_f[len];
		}
		return (dst);
	}
	else if (dst_f < src_f)
		ft_memcpy(dst, src, len);
	return (dst);
}
