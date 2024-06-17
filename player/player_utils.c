/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 05:21:43 by sabras            #+#    #+#             */
/*   Updated: 2024/06/17 22:02:34 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_player_pos(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player->pos.x = x;
				player->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_check_player_pos(t_player *player, t_game_data *game)
{
	if (game->map[player->pos.y][player->pos.x] == COLLEC)
	{
		game->map[player->pos.y][player->pos.x] = FLOOR;
		player->points++;
	}
	else if (game->map[player->pos.y][player->pos.x] == EXIT
		&& (player->points == game->map_data.collectibles))
		ft_destroy_game(*game, 0);
}
