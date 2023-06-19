/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 00:23:01 by bahbibe           #+#    #+#             */
/*   Updated: 2023/06/15 16:03:06 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	ft_word(char *str, char *set)
{
	int	len;
	int	word;
	int	i;
	int	count;

	len = 0;
	word = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (in_set(str[i], set))
			word = 1;
		else
		{
			if (word == 1)
				count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_worddup(char *str, char *set, int *index)
{
	char	*ptr;
	int		count;
	int		pos;
	int		i;

	count = 0;
	i = 0;
	while (in_set(str[*index], set) && str[*index])
		(*index)++;
	pos = *index;
	while (!in_set(str[*index], set) && str[*index])
	{
		count++;
		(*index)++;
	}
	ptr = malloc(count + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str + pos, count + 1);
	return (ptr);
}

static char	**ft_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
	return (NULL);
}

char	**ft_split_set(char const *s, char *set, int *len)
{
	char	**ptr;
	int		count;
	int		i;
	int		index;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = ft_word((char *)s, set);
	ptr = malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = ft_worddup((char *)s, set, &index);
		if (!ptr[i])
			return (ft_free(ptr, i));
		i++;
	}
	ptr[i] = 0;
	if (len)
		*len = i;
	return (ptr);
}
