/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:55:47 by mandric           #+#    #+#             */
/*   Updated: 2020/03/11 09:25:41 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_draw_line_aware_h(t_mega *state, double angle)
{
	double y;
	double x;
	double xq;
	double yq;
	double cx;
	double cy;

	if (angle > 180)
		y = floor(state->player->posY / state->player->std_size) * state->player->std_size - 1;
	else
		y = floor(state->player->posY / state->player->std_size) * state->player->std_size + state->player->std_size;
	if (angle == 0)
		x = 1000000;
	else if (angle == 180)
		x = -1000000;
	else
		x = state->player->posX + (state->player->posY - y)/-tan(M_PI * angle /180);
	if (angle > 180)
		xq = state->player->std_size / -tan(M_PI * angle / 180);
	else
		xq = state->player->std_size / tan(M_PI * angle / 180);
	if (angle < 180)
		yq = state->player->std_size;
	else
		yq = -(state->player->std_size);
	cx = x;
	cy = y;
	double i;
	i = 0;
	while (!(ft_check_mur(state, cx, cy)) && (cx < 10000) && (cx > 0) && (cy < 10000) && (cy > 0))
	{
		cx = cx + xq;
		cy = cy + yq;
		i++;
	}
	state->rc_h_x = cx;
	state->rc_h_y = cy;
	state->rc_xa = fmod(cx,64);
}

void	ft_draw_line_aware_v(t_mega *state, double angle)
{
	double y;
	double x;
	double xq;
	double yq;
	double	cx;
	double	cy;


	if ((angle > 90) && (angle < 270))
		x = floor(state->player->posX / state->player->std_size) * state->player->std_size - 1;
	else
		x = floor(state->player->posX / state->player->std_size) * state->player->std_size + state->player->std_size;
	if (angle == 90)
		y = 1000000;
	else if (angle == 270)
		y = -1000000;
	else
		y = state->player->posY + (state->player->posX - x)*(-tan(M_PI * angle /180));
	if ((angle > 90) && (angle < 270))
		yq = state->player->std_size * -tan(M_PI * (angle ) / 180);
	else
		yq = state->player->std_size * tan(M_PI * (angle) / 180);
	if ((angle > 90) && (angle < 270))
		xq = -(state->player->std_size);
	else
		xq = state->player->std_size;
	cx = x;
	cy = y;
	double i;
	i = 0;
	while (!(ft_check_mur(state, cx, cy)) && (cx < 10000) && (cx > 0) && (cy < 10000) && (cy > 0))
	{
		cx = cx + xq;
		cy = cy + yq;
		i++;
	}
	state->rc_v_x = cx;
	state->rc_v_y = cy;
	state->rc_ya = fmod(cy, 64);
}