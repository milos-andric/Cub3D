/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_porcelain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:18:45 by mandric           #+#    #+#             */
/*   Updated: 2020/03/13 08:32:41 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_draw_world(t_mega *state, double distance, int column, int modulo)
{
	double y1;
	double y2;
	double slice;

	slice = ((double)640 / distance) * (double)100;
	y1 = (slice / (double)2) + (double)((double)state->map->res[1] / (double)2);
	y2 = -(slice / 2.0) + (state->map->res[1] / 2.0);
//	ft_draw_line(state, column, y1, column, y2);
//	dprintf(1, " y2 %f\t y1 %f\t modulo %d\t column%d\t delta %f\n", y2, y1, modulo, column, y1 - y2);
	ft_texture_line(state, y2, y1, modulo, column, 0);
}

void	ft_draw_player(t_mega *state)
{
	double	i;
	double	q;
	double	column;
	double	dist;
	double	angle;

	column = 0;
	q = (state->player->fov / (double)state->map->res[0]);
	i = -(state->player->fov / 2.0);
	ft_draw_b_sqr(state, state->player->posX, state->player->posY, 10, 10);
	while (i < state->player->fov / 2.0)
	{
		angle = ft_regulate(i + state->player->degree);
		ft_draw_line_aware_v(state, angle);
		ft_draw_line_aware_h(state, angle);
		if ((dist = ft_give_length(state->player->posX, state->player->posY, state->rc_h_x, state->rc_h_y)) < ft_give_length(state->player->posX, state->player->posY, state->rc_v_x, state->rc_v_y))
		{
			dist = ft_corct_dist(state, dist, i);
			ft_draw_line(state, state->player->posX, state->player->posY, state->rc_h_x, state->rc_h_y);
			ft_draw_world(state, dist, column, state->rc_xa);
		}
		else
		{
			dist = ft_give_length(state->player->posX, state->player->posY, state->rc_v_x, state->rc_v_y);
			dist = ft_corct_dist(state, dist, i);
			ft_draw_line(state, state->player->posX, state->player->posY, state->rc_v_x, state->rc_v_y);
			ft_draw_world(state, dist, column, state->rc_ya);
		}
		
		i = i + q;
		column++;
	}
}

void	ft_draw_map(t_mega *state,int x, int y, int sqr)
{
	int i;
	int j;
	int border;

	i = 0;
	j = 0;
	border = sqr - 1;
	while (i < state->map->height)
	{
		while(j < state->map->width)
		{
			if(state->map->map[j][i] == 1)
				ft_draw_w_sqr(state, x + (j * sqr), y + (i * sqr), border, border);
			else if(state->map->map[j][i] == 2)
				ft_draw_b_sqr(state, x + (j * sqr), y + (i * sqr), border, border);
			else if(state->map->map[j][i] > 2)
				ft_draw_r_sqr(state, x + (j * sqr), y + (i * sqr), border, border);
			j++;
		}
		j = 0;
		i++;
	}
	ft_draw_player(state);
}