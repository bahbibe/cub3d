/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:53:55 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/29 15:36:46 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final_str;
	size_t	real_len;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		real_len = ft_strlen(s);
	else
		real_len = len;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	final_str = malloc(sizeof(char ) * real_len + 1);
	if (!final_str)
		return (0);
	ft_strncpy(final_str, (char *) s + start, len);
	return (final_str);
}
