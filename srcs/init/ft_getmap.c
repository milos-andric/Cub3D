/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:48:28 by mandric           #+#    #+#             */
/*   Updated: 2020/03/13 08:31:44 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cubed.h"

void	ft_getmap_map(char *f_name, t_type *map)
{
	int fd;

	if (ft_ext_check(f_name, ".cub"))
	{
		if ((fd = open(f_name, O_RDONLY)) == -1)
			ft_exit_message_basic("can't open that map");
		ft_getmap_dim(fd, map);
        close (fd);
		if ((fd = open(f_name, O_RDONLY)) == -1)
			ft_exit_message_basic("can't open that map");
		map->map = ft_alloc_tab(map->height, map->width);
		ft_getmap(fd, map);
        close (fd);
	}
	else
		ft_exit_message_basic("Give me a \'.cub\' file please");
}

void	ft_getmap_dim(int fd, t_type *map)
{
	int	ret;
	int	height;
	int	width;
	char *line;

	height = 0;
	width = 0;
	ret = get_next_line(fd, &line);
	while (ret && (/*ft_strmultichr(line, "012SNEW") == NULL))*/((line[0] != '0') && (line[0] != '1'))))
		ret = get_next_line(fd, &line);
	line = ft_rm_char(line, ' ');
	map->width = ft_strlen(line);
	while ((line[0] == '0') || ((line[0] == '1')))
	{
		if (((int)ft_strlen(line) != map->width) && ret)
			map->valid = 0;
		ret = get_next_line(fd, &line);
		line = ft_rm_char(line, ' ');
		height++;
	}
    map->height = height;
	while(ret != 0)
		ret = get_next_line(fd, &line);
}

int		ft_getmap(int fd, t_type *map)
{
	int		ret;
	int		h;
	int		j;
	char	*line;

	h = 0;
	ret = get_next_line(fd, &line);
	while (ret && ((line[0] != '0') && (line[0] != '1')))
		ret = get_next_line(fd, &line);
	line = ft_rm_char(line, ' ');
	while ((h < map->height))
	{
		j = 0;
		while ((j < map->width))
		{
			map->map[j][h] = line[j] - '0';
			j++;
		}
		h++;
		free(line);
		ret = get_next_line(fd, &line);
		line = ft_rm_char(line, ' ');
	}
	return (0);
}