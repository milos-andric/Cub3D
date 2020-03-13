/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:40:17 by mandric           #+#    #+#             */
/*   Updated: 2020/03/12 11:06:01 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cubed.h"

int		ft_press(int key, t_player *player)
{
	//ft_putnbr_fd(key, 1);
	//ft_putchar_fd('\n', 1);
	(void)player;
	if (key == 0)
		player->posX -= 5;
	else if (key == 1)
		player->posY += 5;
	else if (key == 2)
		player->posX += 5;
	else if (key == 13)
		player->posY -= 5;
	else if (key == 124)
		player->degree += 2;
	else if (key == 123)
		player->degree -= 2;
	if (player->degree < 0)
		player->degree = 360 + player->degree;
	else if (player->degree > 360)
		player->degree = fmod(player->degree, (double)360);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_loop(t_mega *state)
{
	state->img->img = mlx_new_image(state->mlx, 1920, 1080);
	state->img->addr = mlx_get_data_addr(state->img->img, &state->img->bits_per_pixel, &state->img->line_length,
								&state->img->endian);
	ft_draw_map(state, 0, 0, state->player->std_size);
//	ft_draw_text_sqr(state, 150 ,150 ,0);
//	int i = 0;
//	while (++i < state->text->width[0]*20)
//		ft_texture_line(state, -i + 500, i + 500, i % state->text->width[0], i, 0);
    mlx_put_image_to_window(state->mlx, state->mlx_win, state->img->img, 0, 0);
	return (0);
}