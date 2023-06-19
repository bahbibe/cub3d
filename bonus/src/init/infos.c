/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:05:26 by bahbibe           #+#    #+#             */
/*   Updated: 2023/06/17 23:11:14 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*valide_id(char *id)
{
	if (ft_strcmp(id, "EA") || ft_strcmp(id, "NO")
		|| ft_strcmp(id, "SO") || ft_strcmp(id, "WE")
		|| ft_strcmp(id, "F") || ft_strcmp(id, "C"))
		return (id);
	ft_error("Invalid id\n");
	return (NULL);
}

int	valide_color(char *rgb, int *color)
{
	char	**split;
	int		count;
	int		i;
	int		len;

	i = -1 ;
	count = 0 ;
	while (rgb[++i])
	{
		if (rgb[i] == ',' && rgb[i + 1] == ',')
			return (0);
		else if (rgb[i] == ',')
			count++;
		else if (rgb[i] != ',' && !ft_isdigit(rgb[i]))
			return (0);
	}
	split = ft_split_set(rgb, " ,\t\n", &len);
	if (len != 3)
		ft_error("Invalid color\n");
	while (--len >= 0)
		if (ft_atoi(split[len]) < 0 || ft_atoi(split[len]) > 255)
			ft_error("Invalid color\n");
	*color = ft_atoi(split[0]) << 16 | ft_atoi(split[1]) << 8
		| ft_atoi(split[2]) << 0;
	return (tab_free(split), count);
}

char	*valide_content(t_cub3d *cub, char *content, char *id)
{
	int		fd;
	char	*file;

	fd = -1;
	file = ft_strtrim(content, " \t\n");
	free(content);
	if (*id == 'F' || *id == 'C')
	{
		if (*id == 'F' && valide_color(file, &cub->floor) != 2)
			ft_error("Invalid color\n");
		else if (*id == 'C' && valide_color(file, &cub->ceil) != 2)
			ft_error("Invalid color\n");
	}
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error("Cannot open xpm file\n");
	}
	return (close(fd), file);
}

void	parse_info(t_cub3d *cub, t_info *inf, char *file)
{
	char		*id;
	char		*content;
	static int	j;

	while (ft_is_space(*file))
		file++;
	id = ft_substr(file, 0, ft_strchr_index(file, " \t"));
	content = ft_substr(file + ft_strlen(id), 0, ft_strlen(file));
	inf[j].id = valide_id(id);
	inf[j].content = valide_content(cub, content, inf[j].id);
	j++;
}	
