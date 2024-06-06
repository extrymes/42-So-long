/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:57 by sabras            #+#    #+#             */
/*   Updated: 2024/06/06 18:06:45 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static int	ft_check_shape(char **map);
static int	ft_check_borders(char **map);
static int	ft_check_objects(char **map);
static void	ft_check_path(char **map, int x, int y);

int	ft_check_map(char **map)
{
	t_map_coord	start_coord;

	if (!ft_check_shape(map))
		return (ft_putstr("Error\nBad map shape"), 0);
	if (!ft_check_borders(map))
		return (ft_putstr("Error\nMissing map border"), 0);
	if (!ft_check_objects(map))
		return (ft_putstr("Error\nDuplicate start/exit or missing collectible"), 0);
	ft_check_path(map, start_coord.x, start_coord.y);
	return (1);
}

void	ft_check_path(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	ft_check_path(map, x, y + 1);
	ft_check_path(map, x, y - 1);
	ft_check_path(map, x - 1, y);
	ft_check_path(map, x + 1, y);
}

static int	ft_check_shape(char **map)
{
	int	len;
	int	x;
	int	y;

	len = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!map[y][x + 1])
			{
				if (!len)
					len = x;
				if (x != len)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_check_borders(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((x == 0 || y == 0 || !map[y + 1] || !map[y][x + 1]) &&
				(map[y][x] != '1'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_check_objects(char **map)
{
	t_map_objs	map_objs;
	int			x;
	int			y;

	map_objs = ft_new_map_objs();
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				map_objs.starts++;
			if (map[y][x] == 'E')
				map_objs.exits++;
			if (map[y][x] == 'C')
				map_objs.collectibles++;
			x++;
		}
		y++;
	}
	if (map_objs.starts != 1 || map_objs.exits != 1 || map_objs.collectibles == 0)
		return (0);
	return (1);
}
