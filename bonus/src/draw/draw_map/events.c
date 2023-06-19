/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:57:39 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/15 19:21:51 by ybel-hac         ###   ########.fr       */
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

int	mouse_move(int x, int y, t_cub3d *cub)
{
	if ((y <= WINDOW_HEIGTH && y >= 0) && (x <= WINDOW_WIDTH && x >= 0))
	{
		if (x > cub->player.last_x && x < WINDOW_WIDTH)
			cub->player.angel += TURN_SPEED;
		else if (x < cub->player.last_x && x > 0)
			cub->player.angel -= TURN_SPEED;
	}
	cub->player.last_x = x;
	return (1);
}
