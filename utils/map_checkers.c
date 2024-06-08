/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:51:57 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 12:34:25 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static int	ft_check_shape(char **map);
static int	ft_check_borders(char **map);
static int	ft_check_start_exit(char **map);
static int	ft_check_path(char **map, char ***map_copy);

int	ft_check_map(char **map, t_map_data *data)
{
	char		**map_copy;

	if (!ft_check_shape(map))
		return (ft_putstr("Error\nBad map shape"), 0);
	if (!ft_check_borders(map))
		return (ft_putstr("Error\nMissing map border"), 0);
	if (!ft_check_start_exit(map))
		return (ft_putstr("Error\nDuplicate or missing start/exit"), 0);
	*data = ft_get_map_data(map);
	if (data->collectibles == 0)
		return (ft_putstr("Error\nMissing collectible(s)"), 0);
	map_copy = ft_copy_map(map);
	if (!map_copy)
		return (ft_putstr("Allocation fail"), 0);
	ft_browse_map(map_copy, data->start_pos.x, data->exit_pos.y);
	if (!ft_check_path(map, &map_copy))
		return (ft_putstr("Error\nInvalid map path"), 0);
	return (1);
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

static int	ft_check_start_exit(char **map)
{
	int	starts;
	int	exits;
	int	x;
	int	y;

	starts = 0;
	exits = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				starts++;
			if (map[y][x] == 'E')
				exits++;
			x++;
		}
		y++;
	}
	if (starts != 1 || exits != 1)
		return (0);
	return (1);
}

static int	ft_check_path(char **map, char ***map_copy)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'C')
				&& ((*map_copy)[y][x] != '1'))
				return (ft_free_map(map_copy), 0);
			x++;
		}
		y++;
	}
	return (ft_free_map(map_copy), 1);
}
