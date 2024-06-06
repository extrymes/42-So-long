/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:17 by sabras            #+#    #+#             */
/*   Updated: 2024/06/06 17:57:34 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map_coord	ft_fetch_start(char **map);
static t_map_coord	ft_fetch_exit(char **map);
static int			ft_count_collectibles(char **map);

t_map_data	ft_get_map_data(char **map)
{
	t_map_data	map_data;

	map_data.start_pos = ft_fetch_start(map);
	map_data.exit_pos = ft_fetch_exit(map);
	map_data.collectibles = ft_count_collectibles(map);
	return (map_data);
}

t_map_coord	ft_fetch_start(char **map)
{
	t_map_coord	map_coord;
	int			x;
	int			y;

	map_coord = ft_new_map_coord();
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				map_coord.x = x;
				map_coord.y = y;
				return (map_coord);
			}
			x++;
		}
		y++;
	}
	return (map_coord);
}

t_map_coord	ft_fetch_exit(char **map)
{
	t_map_coord	map_coord;
	int			x;
	int			y;

	map_coord = ft_new_map_coord();
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				map_coord.x = x;
				map_coord.y = y;
				return (map_coord);
			}
			x++;
		}
		y++;
	}
	return (map_coord);
}

int	ft_count_collectibles(char **map)
{
	int	collectibles;
	int	x;
	int	y;

	collectibles = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}
