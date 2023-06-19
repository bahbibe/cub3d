/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:17:00 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/17 13:18:16 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	check_direction(t_cub3d *cub, float y, float x)
{
	y -= cub->player.y_inc;
	x -= cub->player.x_inc;
	if (check_wall(cub, x, y + cub->player.y_inc) && cub->player.y_inc <= 0)
		cub->player.direction = NO;
	else if (check_wall(cub, x + cub->player.x_inc, y)
		&& cub->player.x_inc <= 0)
		cub->player.direction = WE;
	else if (check_wall(cub, x, y + cub->player.y_inc))
		cub->player.direction = SO;
	else if (check_wall(cub, x + cub->player.x_inc, y))
		cub->player.direction = EA;
}

void	rays_calc(t_cub3d *cub, t_raycast *obj)
{
	while (!check_wall(cub, (obj->x), (obj->y)))
	{
		obj->y += cub->player.y_inc;
		obj->x += cub->player.x_inc;
	}
}

void	raycast(t_cub3d *cub)
{
	t_raycast	obj;

	obj.angel = cub->player.angel - 30.0;
	obj.start_x = -1;
	while (++obj.start_x < WINDOW_WIDTH)
	{
		obj.rad = obj.angel * (PI / 180.0);
		cub->player.dir_x = cub->player.x - floor(1000000000 * cos(obj.rad));
		cub->player.dir_y = cub->player.y - floor(1000000000 * sin(obj.rad));
		cub->player.dif_x = cub->player.dir_x - cub->player.x;
		cub->player.dif_y = cub->player.dir_y - cub->player.y;
		cub->player.steps = my_abs(cub->player.dif_y);
		if (my_abs(cub->player.dif_x) > my_abs(cub->player.dif_y))
			cub->player.steps = my_abs(cub->player.dif_x);
		cub->player.x_inc = cub->player.dif_x / cub->player.steps;
		cub->player.y_inc = cub->player.dif_y / cub->player.steps;
		obj.y = cub->player.y;
		obj.x = cub->player.x;
		rays_calc(cub, &obj);
		check_direction(cub, obj.y, obj.x);
		draw_walls(cub, obj);
		obj.angel += 60.0 / WINDOW_WIDTH;
	}
}
