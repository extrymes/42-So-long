/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:57 by sabras            #+#    #+#             */
/*   Updated: 2024/10/04 21:27:14 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_shape(char **map_tab);
static int	ft_check_borders(char **map_tab);
static int	ft_check_objects(char **map_tab, t_map map);
static int	ft_check_path(char **map_tab, char **map_copy);

int	ft_check_map(char **map_tab, t_map map)
{
	char	**map_copy;
	int		res;

	if (!ft_check_shape(map_tab))
		return (ft_print_error("Invalid map shape"), 0);
	if (!ft_check_borders(map_tab))
		return (ft_print_error("Missing map border(s)"), 0);
	res = ft_check_objects(map_tab, map);
	if (res == -1)
		return (ft_print_error("Invalid map object(s)"), 0);
	if (res == 0)
		return (ft_print_error("Duplicate/missing start or exit"), 0);
	if (map.collectibles == 0)
		return (ft_print_error("Missing collectible(s)"), 0);
	map_copy = ft_copy_map(map_tab);
	if (!map_copy)
		return (ft_print_error("Allocation fail"), 0);
	ft_browse_map(map_copy, map.start_pos.x, map.exit_pos.y);
	if (!ft_check_path(map_tab, map_copy))
		return (ft_print_error("Invalid map path"), 0);
	return (1);
}

static int	ft_check_shape(char **map_tab)
{
	int	len;
	int	x;
	int	y;

	len = 0;
	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (!map_tab[y][x + 1])
			{
				if (!len)
					len = x;
				if (x != len || x >= 60 || y >= 30)
					return (0);
			}
			x++;
		}
		if (x == 0 && !map_tab[y][x])
			return (0);
		y++;
	}
	return (1);
}

static int	ft_check_borders(char **map_tab)
{
	int	x;
	int	y;

	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if ((x == 0 || y == 0 || !map_tab[y + 1] || !map_tab[y][x + 1])
				&& (map_tab[y][x] != WALL))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_check_objects(char **map_tab, t_map map)
{
	int			x;
	int			y;

	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == START)
				map.starts++;
			else if (map_tab[y][x] == EXIT)
				map.exits++;
			else if (map_tab[y][x] != FLOOR && map_tab[y][x] != WALL
				&& (map_tab[y][x] != COLLEC && map_tab[y][x] != ENEMY))
				map.others++;
			x++;
		}
		y++;
	}
	if (map.others > 0)
		return (-1);
	if (map.starts != 1 || map.exits != 1)
		return (0);
	return (1);
}

static int	ft_check_path(char **map_tab, char **map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if ((map_tab[y][x] == START || map_tab[y][x] == EXIT
				|| (map_tab[y][x] == COLLEC)) && (map_copy[y][x] != WALL))
				return (ft_free_map(map_copy, -1), 0);
			x++;
		}
		y++;
	}
	return (ft_free_map(map_copy, -1), 1);
}
