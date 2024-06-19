/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 03:13:28 by sabras            #+#    #+#             */
/*   Updated: 2024/06/19 03:33:04 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_move_random(char **map, int x, int y);

void	ft_move_enemies(char **map)
{
	int	x;
	int	y;

	srand(time(NULL));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == ENEMY)
			{
				if (ft_move_random(map, x, y))
					map[y][x] = FLOOR;
			}
			x++;
		}
		y++;
	}
}

static int	ft_move_random(char **map, int x, int y)
{
	int	random;

	random = 1 + rand() % (4 - 1 + 1);
	if (random == 1 && map[y - 1][x] == FLOOR)
		return (map[y - 1][x] = ENEMY, 1);
	if (random == 2 && map[y + 1][x] == FLOOR)
		return (map[y + 1][x] = ENEMY, 1);
	if (random == 3 && map[y][x - 1] == FLOOR)
		return (map[y][x - 1] = ENEMY, 1);
	if (random == 4 && map[y][x + 1] == FLOOR)
		return (map[y][x + 1] = ENEMY, 1);
	return (0);
}
