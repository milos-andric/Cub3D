/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:49:56 by mandric           #+#    #+#             */
/*   Updated: 2020/03/06 13:50:29 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_draw_line_low(t_mega *state,	int x1, int y1, int x2, int y2)
{
	double	dx;
	double	dy;
	double	yi;
	double	D;

	dx = x2 - x1;
	dy = y2 - y1;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = 2.0 * dy - dx;
	while (x1 <= x2)
	{
		if(((x1 > 0) && (y1 > 0)) && ((x1 < state->map->res[0]) && (y1 < state->map->res[1])))
			*(int *)(state->img->addr + ((x1 + y1 * state->map->res[0]) * 4)) = (unsigned int)0x00FF0000;
		if(D > 0)
		{
			y1 = y1 + yi;
			D = D - 2.0 * dx;
		}
		D = D + 2.0 * dy;
		x1++;
	}
}

void	ft_draw_line_high(t_mega *state, int x1, int y1, int x2, int y2)
{
	double	dx;
	double	dy;
	double	xi;
	double	D;

	dx = x2 - x1;
	dy = y2 - y1;
	xi = 1;
	if(dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = 2 * dx - dy;
	while(y1 <= y2)
	{
		if(((x1 > 0) && (y1 > 0)) && ((x1 < state->map->res[0]) && (y1 < state->map->res[1])))
			*(int *)(state->img->addr + ((x1 + y1 * state->map->res[0]) * 4)) = (unsigned int)0x00FF0000;
		if(D > 0)
		{
			x1 = x1 + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
		y1++;
	}
}

double		ft_abs(double nb)
{
	return(nb < 0 ? (unsigned int)(nb * -1.0) : (unsigned int)nb);
}

void	ft_draw_line(t_mega *state, int x1, int y1, int x2, int y2)
{
	if(ft_abs(y2 - y1) < ft_abs(x2 - x1))
	{
		if (x1 > x2)
			ft_draw_line_low(state, x2, y2, x1, y1);
		else
			ft_draw_line_low(state, x1, y1, x2, y2);
	}
	else
	{
		if (y1 > y2)
			ft_draw_line_high(state, x2, y2, x1, y1);
		else
			ft_draw_line_high(state, x1, y1, x2, y2);
	}
}

void	ft_draw_line_angle(t_mega *state, double angle, double distance)
{
	double Ax;
	double Ay;

	Ax = state->player->posX + (cos(M_PI * angle / 180.0) * distance);
	Ay = state->player->posY + (sin(M_PI * angle / 180.0) * distance);
	ft_draw_line(state, state->player->posX, state->player->posY, Ax, Ay);
}