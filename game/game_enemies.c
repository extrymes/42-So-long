/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 03:13:28 by sabras            #+#    #+#             */
/*   Updated: 2024/10/04 21:26:46 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_random(char **map_tab, int x, int y);
static void	ft_place_enemies(char **map_tab);

void	ft_move_enemies(char **map_tab)
{
	int	x;
	int	y;

	srand(time(NULL));
	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == ENEMY)
			{
				if (ft_move_random(map_tab, x, y))
					map_tab[y][x] = FLOOR;
			}
			x++;
		}
		y++;
	}
	ft_place_enemies(map_tab);
}

static int	ft_move_random(char **map_tab, int x, int y)
{
	int	random;

	random = 1 + rand() % (4 - 1 + 1);
	if (random == 1 && map_tab[y - 1][x] == FLOOR)
		return (map_tab[y - 1][x] = ENEMY_MOVE, 1);
	if (random == 2 && map_tab[y + 1][x] == FLOOR)
		return (map_tab[y + 1][x] = ENEMY_MOVE, 1);
	if (random == 3 && map_tab[y][x - 1] == FLOOR)
		return (map_tab[y][x - 1] = ENEMY_MOVE, 1);
	if (random == 4 && map_tab[y][x + 1] == FLOOR)
		return (map_tab[y][x + 1] = ENEMY_MOVE, 1);
	return (0);
}

static void	ft_place_enemies(char **map_tab)
{
	int	x;
	int	y;

	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == ENEMY_MOVE)
				map_tab[y][x] = ENEMY;
			x++;
		}
		y++;
	}
}
