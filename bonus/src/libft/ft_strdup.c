/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:45:18 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/20 19:36:34 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (0);
	i = 0;
	while (s1[i])
	{
	dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
