/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:46:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/16 19:04:58 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	colored_pixel_draw(t_cub3d *cub,
						t_walls_draw *obj, int start_x, int offsetX)
{
	int	offset_y;

	obj->offset_y = (obj->start_y - obj->text_start_pixel)
		* ((float)cub->textures[obj->direction].height / obj->real_wall_len);
	offset_y = cub->textures[obj->direction].width * obj->offset_y;
	my_mlx_put_pixel(&cub->map_img,
		obj->start_y, start_x, cub->textures[obj->direction].addr[
		offset_y + (int)offsetX % TILE_SIZE]);
}

// offset_y == the y line in the texture

void	draw_walls(t_cub3d *cub, t_raycast ray)
{
	t_walls_draw	obj;

	obj.dist = sqrt((int)pow(ray.x - cub->player.x, 2)
			+ (int)pow(ray.y - cub->player.y, 2));
	obj.dist = obj.dist * cos(cub->player.angel
			* (PI / 180.0) - ray.angel * (PI / 180.0));
	obj.wall_len = (TILE_SIZE * WINDOW_HEIGTH) / obj.dist;
	obj.real_wall_len = obj.wall_len;
	if (obj.wall_len > WINDOW_HEIGTH)
		obj.wall_len = WINDOW_HEIGTH;
	obj.start_y = (WINDOW_HEIGTH - obj.wall_len) / 2.0;
	obj.text_start_pixel = (WINDOW_HEIGTH - obj.real_wall_len) / 2.0;
	obj.direction = cub->player.direction;
	while (obj.wall_len-- > 0)
	{
		if (cub->player.direction == NO)
			colored_pixel_draw(cub, &obj, ray.start_x, ray.x);
		else if (cub->player.direction == EA)
			colored_pixel_draw(cub, &obj, ray.start_x, ray.y);
		else if (cub->player.direction == SO)
			colored_pixel_draw(cub, &obj, ray.start_x, ray.x);
		else if (cub->player.direction == WE)
			colored_pixel_draw(cub, &obj, ray.start_x, ray.y);
		obj.start_y++;
	}
}

// NO : top
// EA : right
// SO : bottom
// WE : left