/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:04:52 by sabras            #+#    #+#             */
/*   Updated: 2024/06/17 15:32:53 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_image(t_game_data game, char obj, int x, int y);

void	ft_draw_map(char **map, t_game_data game)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ft_put_image(game, map[y][x], x * SPRITE_SIZE, y * SPRITE_SIZE);
			x++;
		}
		y++;
	}
}

void	ft_update_map(char **map, t_game_data game, t_coord last_pos)
{
	t_coord	curr_pos;

	curr_pos = game.player.pos;
	ft_put_image(game, map[last_pos.y][last_pos.x],
		last_pos.x * SPRITE_SIZE, last_pos.y * SPRITE_SIZE);
	ft_put_image(game, map[curr_pos.y][curr_pos.x],
		curr_pos.x * SPRITE_SIZE, curr_pos.y * SPRITE_SIZE);
}

static void	ft_put_image(t_game_data game, char obj, int x, int y)
{
	if (x == game.player.pos.x * SPRITE_SIZE
		&& (y == game.player.pos.y * SPRITE_SIZE))
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.player_img.ptr, x, y);
	else if (obj == '0' || obj == 'P')
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.floor_img.ptr, x, y);
	else if (obj == '1')
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.wall_img.ptr, x, y);
	else if (obj == 'C')
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.collec_img.ptr, x, y);
	else if (obj == 'E')
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.exit_img.ptr, x, y);
}
