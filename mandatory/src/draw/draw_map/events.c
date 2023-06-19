/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:57:39 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/16 20:18:04 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	key_pressed(int keycode, t_cub3d *cub)
{
	if (keycode == UP || keycode == UP_ARROW)
		cub->player.walk = -1;
	else if (keycode == DOWN || keycode == DOWN_ARROW)
		cub->player.walk = 1;
	else if (keycode == RIGHT)
		cub->player.turn = 1;
	else if (keycode == LEFT)
		cub->player.turn = -1;
	else if (keycode == LEFT_ARROW)
		cub->player.rotate = -TURN_SPEED;
	else if (keycode == RIGHT_ARROW)
		cub->player.rotate = TURN_SPEED;
	else if (keycode == ESC)
	{
		mlx_destroy_window(cub->mlx.mlx_ptr, cub->mlx.win);
		ft_exit(cub, 0);
	}
	return (1);
}

int	key_released(int keycode, t_cub3d *cub)
{
	if (keycode == UP || keycode == UP_ARROW)
		cub->player.walk = 0;
	else if (keycode == DOWN || keycode == DOWN_ARROW)
		cub->player.walk = 0;
	else if (keycode == RIGHT)
		cub->player.turn = 0;
	else if (keycode == LEFT)
		cub->player.turn = 0;
	else if (keycode == LEFT_ARROW)
		cub->player.rotate = 0;
	else if (keycode == RIGHT_ARROW)
		cub->player.rotate = 0;
	return (1);
}
