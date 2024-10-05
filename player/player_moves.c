/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:37:54 by sabras            #+#    #+#             */
/*   Updated: 2024/10/05 15:57:47 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_move_up(t_player *player, char **map);
static int	ft_move_down(t_player *player, char **map);
static int	ft_move_left(t_player *player, char **map);
static int	ft_move_right(t_player *player, char **map);

int	ft_player_move(t_player *player, char **map_tab, int keysym)
{
	const t_move_keys	keys[] = {
	{KEY_W, ft_move_up},
	{KEY_S, ft_move_down},
	{KEY_A, ft_move_left},
	{KEY_D, ft_move_right}
	};
	int					size;
	int					i;

	size = sizeof(keys) / sizeof(keys[0]);
	i = 0;
	while (i < size)
	{
		if (keys[i].keysym == keysym)
			return (keys[i].ft(player, map_tab));
		i++;
	}
	return (0);
}

static int	ft_move_up(t_player *player, char **map_tab)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x;
	new_pos.y = player->pos.y - 1;
	if (map_tab[new_pos.y][new_pos.x] == WALL)
		return (0);
	player->pos = new_pos;
	player->moves++;
	return (1);
}

static int	ft_move_down(t_player *player, char **map_tab)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x;
	new_pos.y = player->pos.y + 1;
	if (map_tab[new_pos.y][new_pos.x] == WALL)
		return (0);
	player->pos = new_pos;
	player->moves++;
	return (1);
}

static int	ft_move_left(t_player *player, char **map_tab)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x - 1;
	new_pos.y = player->pos.y;
	if (map_tab[new_pos.y][new_pos.x] == WALL)
		return (0);
	player->pos = new_pos;
	player->moves++;
	return (1);
}

static int	ft_move_right(t_player *player, char **map_tab)
{
	t_coord	new_pos;

	new_pos.x = player->pos.x + 1;
	new_pos.y = player->pos.y;
	if (map_tab[new_pos.y][new_pos.x] == WALL)
		return (0);
	player->pos = new_pos;
	player->moves++;
	return (1);
}
