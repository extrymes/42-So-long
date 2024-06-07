/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:17 by sabras            #+#    #+#             */
/*   Updated: 2024/06/07 11:41:40 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static t_coord	ft_fetch_start(char **map);
static t_coord	ft_fetch_exit(char **map);
static int		ft_count_collectibles(char **map);

t_map_data	ft_get_map_data(char **map)
{
	t_map_data	map_data;

	map_data.start_pos = ft_fetch_start(map);
	map_data.exit_pos = ft_fetch_exit(map);
	map_data.collectibles = ft_count_collectibles(map);
	return (map_data);
}

static t_coord	ft_fetch_start(char **map)
{
	t_coord	pos;
	int		x;
	int		y;

	pos = ft_new_coord();
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

static t_coord	ft_fetch_exit(char **map)
{
	t_coord	pos;
	int		x;
	int		y;

	pos = ft_new_coord();
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

static int	ft_count_collectibles(char **map)
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
