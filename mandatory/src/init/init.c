/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:51:23 by bahbibe           #+#    #+#             */
/*   Updated: 2023/06/18 14:49:05 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_empty_file(int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		if (!is_empty(line))
			i = 0;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	check_args(t_cub3d *cub, int ac, char *file)
{
	int	fd;
	int	pos;

	if (ac != 2)
		return (ft_error("Usage: ./cub3d <map_file.cub>\n"), 0);
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		return (ft_error("Is a directory\n"), close(fd), 0);
	pos = ft_strlen(file) - 4;
	if (ft_strncmp(file + pos, ".cub", 4))
		return (ft_error("Invalid file <*.cub>\n"), 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_error("Cannot read file\n"), close(fd), 0);
	if (is_empty_file(fd))
		ft_error("Empty file\n");
	close (fd);
	fd = open(file, O_RDONLY);
	cub->full_file = alloc_file(cub, fd);
	if (!cub->full_file)
		ft_error("Invalid file\n");
	return (1);
}

char	**alloc_file(t_cub3d *cub, int fd)
{
	char	*line;

	cub->lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		cub->lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	cub->full_file = ft_calloc(sizeof(char *), cub->lines + 1);
	if (!cub->full_file)
		return (close(fd), NULL);
	return (close(fd), cub->full_file);
}

void	init_cub(t_cub3d *cub, char *file)
{
	int		i ;
	int		fd ;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!is_info(line))
			break ;
		if (!is_empty(line))
			cub->full_file[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		cub->full_file[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	init_infos(cub);
}

void	init_infos(t_cub3d *cub)
{
	int	i;
	int	j;

	i = -1;
	cub->info_size = 0;
	while (cub->full_file[++i])
		if (is_info(cub->full_file[i]))
			cub->info_size++;
	if (cub->info_size != 6)
		ft_error("Invalid file\n");
	cub->info = ft_calloc(sizeof(t_info), cub->info_size);
	i = -1;
	while (cub->full_file[++i])
		if (is_info(cub->full_file[i]))
			parse_info(cub, cub->info, cub->full_file[i]);
	j = -1;
	while (++j < cub->info_size)
	{
		i = j;
		while (++i < 6)
			if (ft_strcmp(cub->info[j].id, cub->info[i].id))
				ft_error("Duplicate infos\n");
	}
	init_map(cub);
}
