/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:50:56 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/17 18:44:55 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	tab_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_utils(t_cub3d cub)
{
	int	i;

	i = 0;
	if (cub.info_size > 0)
	{
		while (i < cub.info_size)
		{
			free(cub.info[i].id);
			free(cub.info[i].content);
			i++;
		}
		free(cub.info);
	}
	if (cub.full_file)
		tab_free(cub.full_file);
	if (cub.map)
		tab_free(cub.map);
}

void	ft_exit(t_cub3d *cub, int error)
{
	int	i;

	i = -1;
	(void)cub;
	while (++i < cub->info_size)
	{
		free(cub->info[i].content);
		free(cub->info[i].id);
	}
	free(cub->info);
	tab_free(cub->full_file);
	tab_free(cub->map);
	exit(error);
}

int	exit_btn(t_cub3d *cub)
{
	ft_exit(cub, 0);
	return (1);
}
