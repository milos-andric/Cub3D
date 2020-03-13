/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandric <mandric@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:21:45 by mandric           #+#    #+#             */
/*   Updated: 2020/03/09 17:29:21 by mandric          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cubed.h"

int	main(int argc, char *argv[])
{
	t_type		map;
	t_data		img;
	t_player	player;
	t_mega		state;
	t_texture	text;

	if (argc != 2)
		ft_exit_message_basic("Please provide file\n");
	else
	{
		ft_read_file(argv[1], &map);
	}
	state.map = &map;
	state.text = &text;
	state.player = &player;
	state.img = &img;
 	ft_init_player(&player, &map);
	state.mlx = mlx_init();
	state.mlx_win = mlx_new_window(state.mlx, state.map->res[0],
									state.map->res[1], "Cubed");
	ft_load_textures(&state);
	mlx_hook(state.mlx_win, 2, 0, ft_press, state.player);
	mlx_loop_hook(state.mlx, ft_loop, &state);
	mlx_loop(state.mlx);
	return (0);
}