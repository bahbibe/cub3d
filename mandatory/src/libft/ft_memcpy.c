/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:56:47 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 13:08:40 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src_f;
	char	*dst_f;

	if (dst == src)
		return (dst);
	src_f = (char *) src;
	dst_f = (char *) dst;
	i = 0;
	while ((src_f || dst_f) && i < n)
	{
		dst_f[i] = src_f[i];
		i++;
	}
	return (dst);
}
