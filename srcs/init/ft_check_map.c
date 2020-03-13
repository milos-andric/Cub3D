/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:51:36 by mandric           #+#    #+#             */
/*   Updated: 2020/03/05 09:56:06 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_check_map(t_type *map)
{
	//dprintf(1, "%d\n", map->valid);
	ft_check_borders(map);
	if (map->valid == 0)
		ft_exit_message("\033[1;31mThe submitted map is not closed.\n\033[0m", map);
	ft_check_char(map);
	if (map->valid == 0)
		ft_exit_message("Illegal character in the submitted map.", map);
	ft_check_begin_char(map);
	if (map->valid == 0)
		ft_exit_message("There are two or more starting point.", map);
}

int		ft_ext_check(char *str, char *end)
{
	int len;
	int count;

	len = ft_strlen(str) - 1;
	count = ft_strlen(end) - 1;
	if (len == count)
		return (0);
	while ((str[len--] == end[count]) && ((count > 0) && (len > 0)))
		count--;
	if (count == 0)
		return (1);
	else
		return (0);
}

void	ft_check_borders(t_type *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (map->width - 1))
	{
		if (map->map[i][j] != 1)
			map->valid = 0;
		i++;
	}
	while (j < (map->height - 1))
	{
		if (map->map[i][j] != 1)
			map->valid = 0;
		j++;
	}
	while (i > 0)
	{
		if (map->map[i][j] != 1)
			map->valid = 0;
		i--;
	}
	while (j > 0)
	{
		if (map->map[i][j] != 1)
			map->valid = 0;
		j--;
	}
}

void	ft_check_begin_char(t_type *map)
{
	int i;
	int j;
	int flag;
	int dir;

	i = 0;
	j = 0;
	flag = 0;
	dir = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			dir = ft_is_good_char(map->map[j][i]);
			if ((dir >= 3) && (dir <= 6))
				flag++;
			j++;
		}
		i++;
		j = 0;
	}
	if (flag != 1)
		map->valid = 0;
}

void	ft_check_char(t_type *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			if (ft_is_good_char(map->map[j][i]) == -1)
				map->valid = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

int		ft_is_good_char(int var)
{
	if (var == 0)
		return (0);
	else if (var == 1)
		return (1);
	else if (var == 2)
		return (2);
	else if (var == ('N' - 48))
		return (5);
	else if (var == ('S' - 48))
		return (3);
	else if (var == ('E' - 48))
		return (4);
	else if (var == ('W' - 48))
		return (6);
	else
		return (-1);
}
