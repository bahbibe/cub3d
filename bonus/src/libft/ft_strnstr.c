/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:14:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 13:27:28 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *)(haystack));
	if (!len)
		return (0);
	while (haystack[i] && i + ft_strlen(needle) <= len)
	{
		if (haystack[i] == needle[0])
			if (ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
				return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
