/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:41:53 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/18 14:05:53 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str_alloc;

	if (size && count >= (SIZE_MAX / size))
		return (0);
	str_alloc = malloc(count * size);
	if (!str_alloc)
		return ((void *)0);
	ft_bzero(str_alloc, count * size);
	return (str_alloc);
}
