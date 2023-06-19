/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:24:33 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/10/31 13:27:47 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	search_in(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*final_str;
	size_t	i;
	size_t	j;
	size_t	strlen;

	if (!s1 || !set)
		return (0);
	strlen = ft_strlen(s1);
	j = 0;
	i = 0;
	while (s1[i] && search_in(s1[i], set) == 0)
		i++;
	while (--strlen > 0)
		if (search_in(s1[strlen], set))
			break ;
	if (strlen == 0)
		return (ft_strdup(""));
	final_str = malloc(sizeof(char) * (strlen - i + 2));
	if (!final_str)
		return (0);
	while (s1[i] && i <= strlen)
		final_str[j++] = s1[i++];
	final_str[j] = '\0';
	return (final_str);
}
