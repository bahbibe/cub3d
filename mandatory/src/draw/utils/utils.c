/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:38:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/15 16:01:26 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	my_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

char	*get_info_value(t_cub3d *cub, const char *id)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strcmp(cub->info[i].id, id))
			return (cub->info[i].content);
		i++;
	}
	return (0);
}

void	ft_swap(char *c1, char *c2)
{
	char	temp;

	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
