/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:40:11 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/13 16:59:57 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if (s[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (0);
}

int	ft_strchr_index(const char *s, char *c)
{
	int		i;
	int		j;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		j = -1;
		while (c[++j])
			if (s[i] == c[j])
				return (i);
		i++;
	}
	return (-1);
}
