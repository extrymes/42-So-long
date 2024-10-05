/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:23:54 by sabras            #+#    #+#             */
/*   Updated: 2024/10/04 21:26:50 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	ft_init_game(void)
{
	t_game	game;

	game.mlx_ptr = NULL;
	game.win_ptr = NULL;
	game.map.tab = NULL;
	game.map.starts = 0;
	game.map.exits = 0;
	game.map.others = 0;
	game.floor_spr.ptr = NULL;
	game.wall_spr.ptr = NULL;
	game.collec_spr.ptr = NULL;
	game.player_spr.ptr = NULL;
	game.exit_spr.ptr = NULL;
	game.enemy_spr.ptr = NULL;
	return (game);
}

t_player	ft_new_player(void)
{
	t_player	player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.moves = 0;
	player.points = 0;
	return (player);
}

t_coord	ft_new_coord(void)
{
	t_coord	pos;

	pos.x = 0;
	pos.y = 0;
	return (pos);
}
