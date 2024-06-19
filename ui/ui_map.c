/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:04:52 by sabras            #+#    #+#             */
/*   Updated: 2024/06/19 06:56:48 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_image(t_game game, char obj, int x, int y);

void	ft_render_map(char **map_tab, t_game game)
{
	int		x;
	int		y;

	mlx_clear_window(game.mlx_ptr, game.win_ptr);
	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			ft_put_image(game, map_tab[y][x], x * SPRITE_SIZE, y * SPRITE_SIZE);
			x++;
		}
		y++;
	}
	ft_display_hud(game, game.player.moves, game.player.points);
}

void	ft_update_map(char **map_tab, t_game game, t_coord last_pos)
{
	t_coord	curr_pos;

	curr_pos = game.player.pos;
	ft_put_image(game, map_tab[last_pos.y][last_pos.x],
		last_pos.x * SPRITE_SIZE, last_pos.y * SPRITE_SIZE);
	ft_put_image(game, map_tab[curr_pos.y][curr_pos.x],
		curr_pos.x * SPRITE_SIZE, curr_pos.y * SPRITE_SIZE);
}

static void	ft_put_image(t_game game, char obj, int x, int y)
{
	if (x == game.player.pos.x * SPRITE_SIZE
		&& (y == game.player.pos.y * SPRITE_SIZE))
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.player_spr.ptr, x, y);
	else if (obj == FLOOR || obj == START)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.floor_spr.ptr, x, y);
	else if (obj == WALL)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.wall_spr.ptr, x, y);
	else if (obj == COLLEC)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.collec_spr.ptr, x, y);
	else if (obj == EXIT)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.exit_spr.ptr, x, y);
	else if (obj == ENEMY)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.enemy_spr.ptr, x, y);
}
