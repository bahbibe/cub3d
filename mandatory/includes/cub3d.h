/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:52:05 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/06/18 14:37:17 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "math.h"
# include "stdbool.h"
# include "stdlib.h"
# include "stdio.h"
# include "fcntl.h"
# include "unistd.h"
# include "../src/libft/libft.h"
# include "mlx.h"

# define NO 				0
# define EA 				1
# define SO 				2
# define WE 				3
# define RED 				0x00cc5803
# define GREEN 				0x00e2711d
# define BLUE 				0x00ff9505
# define YELLOW 			0x00ffb627
# define LINE_COLOR 		0x00ff0000
# define LINE_GREEN_COLOR	0x0000ff00
# define WALL_COLOR 		0x00ffffff
# define FLOOR_COLOR 		0x0000ffff
# define PLAYER_COLOR 		0x00ff0000
# define TILE_SIZE			100
# define SCALE_SIZE 		0.07
# define PI					3.141592653589793238
# define UP					13
# define UP_ARROW			126
# define DOWN				1
# define DOWN_ARROW			125
# define RIGHT				2
# define LEFT				0
# define ESC				53
# define RIGHT_ARROW		124
# define LEFT_ARROW			123
# define PLAYER_SPEED		20
# define TURN_SPEED			2
# define ONE_DEGRESS 		0.0174533
# define WINDOW_WIDTH 		1280
# define WINDOW_HEIGTH 		720
# define ID					1
# define CONTENT			0
# define TEXTURE			1
# define COLOR				2

typedef struct s_walls_draw
{
	float	dist;
	float	wall_len;
	int		start_y;
	int		text_start_pixel;
	int		offset_y;
	float	real_wall_len;
	int		direction;
}	t_walls_draw;

typedef struct s_raycast
{
	float		y;
	float		x;
	float		rad;
	float		angel;
	int			rays;
	float		dist;
	float		wall_len;
	int			start_y;
	int			start_x;
}	t_raycast;

typedef struct s_textures
{
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*pixel_data;
	void	*img;
	int		*addr;
}	t_textures;

typedef struct s_info
{
	char	*id;
	char	*content;
}	t_info;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}	t_mlx;

typedef struct s_my_mlx
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*pixel_data;
	void	*img;
	int		width;
	int		height;
	int		color;
}	t_my_mlx;

typedef struct s_obj
{
	int	y_pos;
	int	x_pos;
}	t_obj;

typedef struct s_player
{
	float	y;
	float	x;
	float	dir_x;
	float	dir_y;
	float	dif_x;
	float	dif_y;
	float	steps;
	float	x_inc;
	float	y_inc;
	float	angel;
	float	turn_speed;
	float	walk_speed;
	int		turn;
	int		walk;
	int		rotate;
	int		direction;
	int		last_x;
}	t_player;

typedef struct s_cub3d
{
	t_my_mlx	mini_img;
	t_my_mlx	map_img;
	char		**full_file;
	t_info		*info;
	char		**map;
	int			info_size;
	int			lines;
	int			map_height;
	int			map_width;
	int			window_height;
	int			window_width;
	t_mlx		mlx;
	t_mlx		map_mlx;
	t_player	player;
	t_textures	*textures;
	char		p;
	int			ceil;
	int			floor;
}	t_cub3d;

int		is_empty(char *s);
int		is_closed(t_cub3d *cub);
int		check_token(t_cub3d *cub);
int		in_set(char c, char *set);
int		get_height(char **s);
int		ft_is_space(int c);
void	ft_error(char *s);
char	**ft_split_set(char const *s, char *set, int *len);
int		check_args(t_cub3d *cub, int ac, char *file);
void	init_cub(t_cub3d *cub, char *file);
char	**alloc_file(t_cub3d *cub, int fd);
char	*valide_id(char *id);
void	init_infos(t_cub3d *cub);
void	parse_info(t_cub3d *cub, t_info *inf, char *file);
void	init_map(t_cub3d *cub);
int		is_info(char *line);
void	check_map(t_cub3d *cub);
char	*dup_line(char *src, int len);
void	tab_free(char **tab);
//?  draw
void	ft_swap(char *c1, char *c2);
void	free_utils(t_cub3d cub);
void	ft_exit(t_cub3d *cub, int error);
int		my_abs(int x);
char	*get_info_value(t_cub3d *cub, const char *id);
int		exit_btn(t_cub3d *cub);
void	draw_2dmap(t_cub3d *cub);
int		render_2dmap(t_cub3d *cub);
void	my_mlx_put_pixel(t_my_mlx *data, int y, int x, int color);
void	new_main_img(t_cub3d *cub, t_my_mlx *data, int width, int height);
void	new_obj(t_my_mlx *data, t_obj img, int color, int size);
void	init_player(t_cub3d *cub);
int		check_wall(t_cub3d *cub, float new_x, float new_y);
void	move_player(t_cub3d *cub, float x, float y);
int		key_pressed(int keycode, t_cub3d *cub);
int		key_released(int keycode, t_cub3d *cub);
int		mouse_move(int x, int y, t_cub3d *cub);
void	new_black_obj(t_my_mlx *data, int hiegth, int width);
void	draw_walls(t_cub3d *cub, t_raycast ray);
//? player
void	init_player(t_cub3d *cub);
void	raycast(t_cub3d *cub);
void	draw_player(t_cub3d *cub, float y_pos, float x_pos, int color);
#endif
