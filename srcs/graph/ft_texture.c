/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:02:40 by mandric           #+#    #+#             */
/*   Updated: 2020/03/12 11:25:45 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

void	ft_load_textures(t_mega *state)
{
	void *temp;
	temp = mlx_xpm_file_to_image(state->mlx, state->map->no, &state->text->width[0], &state->text->height[0]);
	state->text->textures[0] = (int *)mlx_get_data_addr(temp, &state->img->bits_per_pixel, &state->img->line_length, &state->img->endian);
	//ft_draw_text_sqr(state, 0, 0, state->text, height, text);
	temp = mlx_xpm_file_to_image(state->mlx, state->map->we, &state->text->width[1], &state->text->height[1]);
	state->text->textures[1] = (int *)mlx_get_data_addr(temp, &state->img->bits_per_pixel, &state->img->line_length, &state->img->endian);
	
	temp = mlx_xpm_file_to_image(state->mlx, state->map->so, &state->text->width[2], &state->text->height[2]);
	state->text->textures[2] = (int *)mlx_get_data_addr(temp, &state->img->bits_per_pixel, &state->img->line_length, &state->img->endian);

	temp = mlx_xpm_file_to_image(state->mlx, state->map->ea, &state->text->width[3], &state->text->height[3]);
	state->text->textures[3] = (int *)mlx_get_data_addr(temp, &state->img->bits_per_pixel, &state->img->line_length, &state->img->endian);
}

void	ft_draw_text_sqr(t_mega *state, int x, int y, int texture)
{
	int i;
	int j;

	i = y;
	j = x;
	while ((i < (state->text->height[texture] + y)) && (i < state->map->res[1]))
	{
		while ((j < (state->text->width[texture] + x)) && (j < state->map->res[0]))
		{
			*(int *)(state->img->addr + (int)((j + i * state->map->res[0]) * 4)) = *(state->text->textures[texture] + (int)(((j - x) + (i - y) * state->text->width[texture])));
			j++;
		}
		j = x;
		i++;
	}
}

void	ft_texture_line(t_mega *state, int y1, int y2, int modulo, int column, int texture)
{
	int		delta = y2 - y1;
	int		i = 0;
	double	j = 0;
	double	ratio = (double)delta / (double)state->text->height[texture];
	
	//dprintf(1, "ratio : %d\n", modulo);
	while (i < (state->text->height[texture] * ratio) && ((j >= 0) && (j < state->text->height[texture])))
	{
		if (((i + y1) >= 0) && ((i + y1) < state->map->res[1]))
			*(int *)(state->img->addr + (int)((column + (i + y1) * state->map->res[0]) * 4)) = *(state->text->textures[texture] + (int)(((modulo) + (int)j * state->text->width[texture])));
		i++;
		j += (1.0/ratio);
	//	dprintf(1, "j : %f\tint = %d\tratio : %f\n", j, (int)j, ratio);
	}
}