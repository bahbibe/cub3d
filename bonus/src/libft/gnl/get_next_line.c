/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:17:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/10 16:42:52 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_new_exicted(char *last)
{
	size_t	i;

	i = 0;
	if (!last)
		return (0);
	while (last[i])
	{
		if (last[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*last[OPEN_MAX];
	char			txt[BUFFER_SIZE + 1];
	char			*line;
	int				read_nb;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	line = NULL;
	read_nb = 1;
	while (read_nb && !check_new_exicted(last[fd]))
	{
		read_nb = read(fd, txt, BUFFER_SIZE);
		if (read_nb == -1)
			return (free_func(&last[fd]));
		txt[read_nb] = '\0';
		if (read_nb == 0 && last[fd])
			return (check_read_return(&last[fd], line));
		if (read_nb == 0)
			return (0);
		last[fd] = ft_strjoin(last[fd], txt);
	}
	line = get_before_new(last[fd]);
	last[fd] = get_after_new(last[fd]);
	return (line);
}

char	*free_func(char **s1)
{
	free(*s1);
	*s1 = NULL;
	return (0);
}

char	*check_read_return(char **last, char *line)
{
	if (!*(*last))
	{
		free(*last);
		*last = NULL;
		return (0);
	}
	line = get_substring(*last, get_str_len(*last));
	free(*last);
	*last = NULL;
	return (line);
}
