/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:08:41 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 14:18:58 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game_data	ft_init_game(void)
{
	t_game_data	game;

	game.map = NULL;
	game.mlx_ptr = NULL;
	game.win_ptr = NULL;
	game.player_img.ptr = NULL;
	game.exit_img.ptr = NULL;
	game.collec_img.ptr = NULL;
	game.wall_img.ptr = NULL;
	game.space_img.ptr = NULL;
	return (game);
}

t_coord	ft_new_coord(void)
{
	t_coord	pos;

	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_map_objs	ft_new_objs(void)
{
	t_map_objs	objs;

	objs.starts = 0;
	objs.exits = 0;
	objs.others = 0;
	return (objs);
}

t_player	ft_new_player(void)
{
	t_player	player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.points = 0;
	return (player);
}
