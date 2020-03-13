/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:05:11 by mandric           #+#    #+#             */
/*   Updated: 2020/03/06 15:28:18 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_draw_b_sqr(t_mega *state, int x, int y, int width, int height)
{
	int i;
	int j;

	i = y;
	j = x;
	while ((i < (height + y)) && (i < state->map->res[1]))
	{
		while ((j < (width + x)) && (j < state->map->res[0]))
		{
			*(int *)(state->img->addr + (int)((j + i * state->map->res[0]) * 4)) = (unsigned int)0x002080D0;
			j++;
		}
		j = x;
		i++;
	}
}

void	ft_draw_w_sqr(t_mega *state, int x, int y, int width, int height)
{
	int i;
	int j;

	i = y;
	j = x;
	while ((i < (height + y)) && (i < state->map->res[1]))
	{
		while ((j < (width + x)) && (j < state->map->res[0]))
		{
			*(int *)(state->img->addr + ((j + i * state->map->res[0]) * 4)) = (unsigned int)0x00DDDDBB;
			j++;
		}
		j = x;
		i++;
	}
}

void	ft_draw_r_sqr(t_mega *state, int x, int y, int width, int height)
{
	int i;
	int j;

	i = y;
	j = x;
	while ((i < (height + y)) && (i < state->map->res[1]))
	{
		while ((j < (width + x)) && (j < state->map->res[0]))
		{
			*(int *)(state->img->addr + ((j + i * state->map->res[0]) * 4)) = (unsigned int)0x00AA0000;
			j++;
		}
		j = x;
		i++;
	}
}
