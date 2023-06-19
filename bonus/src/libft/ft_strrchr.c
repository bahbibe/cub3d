/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:42:04 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/01 01:02:50 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	str_len;

	str_len = (int)ft_strlen(s);
	while (str_len >= 0)
	{
		if (s[str_len] == (char)c)
			return ((char *)s + str_len);
		str_len--;
	}
	return (0);
}
