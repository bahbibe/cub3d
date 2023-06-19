/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:25:20 by bahbibe           #+#    #+#             */
/*   Updated: 2023/06/18 14:31:56 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**dup_map(t_cub3d *cub)
{
	char	**dup;
	int		i;

	dup = ft_calloc(sizeof(char *), cub->map_height + 3);
	dup[0] = dup_line(NULL, cub->map_width + 3);
	i = 0;
	while (cub->map[++i - 1])
		dup[i] = dup_line(cub->map[i - 1], cub->map_width + 3);
	dup[i] = dup_line(NULL, cub->map_width + 3);
	return (dup);
}

void	init_map(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	cub->map_width = 0;
	while (cub->full_file[i])
		i++;
	cub->map_height = i - cub->info_size;
	if (!cub->map_height)
		ft_error("Invalid map\n");
	cub->map = ft_calloc(sizeof(char *), cub->map_height + 1);
	i = cub->info_size - 1;
	while (cub->full_file[++i])
	{
		if (ft_strlen(cub->full_file[i]) > (size_t)cub->map_width)
			cub->map_width = ft_strlen(cub->full_file[i]) - 1;
		if (is_empty(cub->full_file[i]))
			ft_error("Invalid map\n");
		cub->map[++j] = ft_substr(cub->full_file[i], 0,
				ft_strchr_index(cub->full_file[i], "\n"));
	}
	if (ft_strchr_index(cub->full_file[i - 1], "\n") != -1)
		ft_error("Invalid map\n");
	check_map(cub);
}

void	check_map(t_cub3d *cub)
{
	if (!is_closed(cub))
		ft_error("Invalid map\n");
	if (check_token(cub))
		ft_error("Invalid position\n");
	if (cub->p == 'N')
		cub->player.angel = 90;
	if (cub->p == 'E')
		cub->player.angel = 180;
	if (cub->p == 'S')
		cub->player.angel = 270;
	if (cub->p == 'W')
		cub->player.angel = 0;
}

int	is_closed(t_cub3d *cub)
{
	char	**dup;
	int		y;
	int		x;

	y = -1;
	dup = dup_map(cub);
	while (dup[++y])
	{
		x = -1;
		while (dup[y][++x])
		{
			if (dup[y][x] == 'x')
			{
				if ((dup[y][x + 1] && !in_set(dup[y][x + 1], "x1"))
					|| (dup[y + 1] && !in_set(dup[y + 1][x], "x1")))
					return (0);
				if ((x != 0 && !in_set(dup[y][x - 1], "x1"))
					|| (y != 0 && !in_set(dup[y - 1][x], "x1")))
					return (0);
			}
		}
	}
	tab_free(dup);
	return (1);
}

int	check_token(t_cub3d *cub)
{
	int	count;
	int	x;
	int	y;

	count = -1;
	y = -1;
	while (cub->map[++y])
	{	
		x = -1;
		while (cub->map[y][++x])
		{
			if (in_set(cub->map[y][x], "NWES"))
			{
				cub->p = cub->map[y][x];
				count++;
			}
			else if (!in_set(cub->map[y][x], " NWES01\t"))
				ft_error("Invalid token\n");
		}
	}
	return (count);
}
