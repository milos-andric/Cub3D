/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:59:01 by mandric           #+#    #+#             */
/*   Updated: 2020/03/06 10:47:53 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_init_player(t_player *player, t_type *map)
{
	double i;
	double j;

	i = 0;
	j = 0;
	while (j < (double)map->height)
	{
		while (i < (double)map->width)
		{
			if (map->map[(int)i][(int)j] > 2)
			{
				player->posX = i * 64 + 32;
				player->posY = j * 64 + 32;
			}
			i++;
		}
		i = 0;
		j++;
	}
	player->degree = 90;
	player->std_size = 64;
	player->fov = 60;
}

double	ft_regulate(double angle)
{
	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 360)
		angle = fmod(angle, (double)360);
	return (angle);
}

double	ft_give_length(double x1, double y1, double x2, double y2)
{
	double dx;
	double dy;

	dx = x2 - x1;
	dy = y2 - y1;
	dx = pow(dx, 2);
	dy = pow(dy, 2);
	return (sqrt((dy + dx)));
}

double	ft_map_size_calc(t_mega *state, double percent)
{
	double sqr;

	if (state->map->height > state->map->width)
		sqr = ((state->map->res[1] / 100.0) * percent) / state->map->height;
	else
		sqr = ((state->map->res[0] / 100.0) * percent) / state->map->width;
	return (sqr);
}

double	ft_check_mur(t_mega *state, double x, double y)
{
	if (((x / 64.0) >= state->map->width) || ((y / 64.0) >= state->map->height))
		return (1);
	if (((x / 64.0) < 0) || ((y / 64.0) < 0))
		return (1);
	return (state->map->map[(int)x / 64][(int)y / 64] != 1 ? 0 : 1);
}