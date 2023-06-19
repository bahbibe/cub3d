/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:13:53 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 13:04:25 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_f;
	unsigned char	*s2_f;

	s1_f = (unsigned char *)s1;
	s2_f = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_f[i] != s2_f[i])
			return (s1_f[i] - s2_f[i]);
		i++;
	}
	return (0);
}
