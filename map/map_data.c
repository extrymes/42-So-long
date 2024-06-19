/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:39 by sabras            #+#    #+#             */
/*   Updated: 2024/06/19 06:33:38 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_coord	ft_fetch_start(char **map_tab);
static t_coord	ft_fetch_exit(char **map_tab);
static int		ft_count_collectibles(char **map_tab);

void	ft_get_map_data(char **map_tab, t_map *map)
{
	map->start_pos = ft_fetch_start(map_tab);
	map->exit_pos = ft_fetch_exit(map_tab);
	map->collectibles = ft_count_collectibles(map_tab);
}

static t_coord	ft_fetch_start(char **map_tab)
{
	t_coord	pos;
	int		x;
	int		y;

	pos = ft_new_coord();
	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == START)
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

static t_coord	ft_fetch_exit(char **map_tab)
{
	t_coord	pos;
	int		x;
	int		y;

	pos = ft_new_coord();
	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == EXIT)
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

static int	ft_count_collectibles(char **map_tab)
{
	int	collectibles;
	int	x;
	int	y;

	collectibles = 0;
	y = 0;
	while (map_tab[y])
	{
		x = 0;
		while (map_tab[y][x])
		{
			if (map_tab[y][x] == COLLEC)
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}
