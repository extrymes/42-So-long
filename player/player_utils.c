/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 05:21:43 by sabras            #+#    #+#             */
/*   Updated: 2024/06/19 07:05:29 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_get_player_pos(char **map_tab, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == 'P')
			{
				player->pos.x = x;
				player->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_check_player_pos(char **map_tab, t_player *player, t_game *game)
{
	if (map_tab[player->pos.y][player->pos.x] == COLLEC)
	{
		map_tab[player->pos.y][player->pos.x] = FLOOR;
		player->points++;
	}
	else if (map_tab[player->pos.y][player->pos.x] == EXIT
		&& (player->points == game->map.collectibles))
	{
		ft_print_you_win();
		ft_destroy_game(*game, 0);
	}
	else if (map_tab[player->pos.y][player->pos.x] == ENEMY)
	{
		ft_print_you_died();
		ft_destroy_game(*game, 0);
	}
}
