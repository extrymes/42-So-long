/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:37:54 by sabras            #+#    #+#             */
/*   Updated: 2024/06/13 10:44:45 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_move_up(t_player *player);
static void	ft_move_down(t_player *player);
static void	ft_move_left(t_player *player);
static void	ft_move_right(t_player *player);

void	ft_player_move(int keysim, t_player *player)
{
	t_move_keys	keys[] = {
		{}
	};
	int			size;
	int			i;

	size = sizeof(keys) / sizeof(keys[0]);
	while (i < size)
	{
		if (keys[i].keysim == keysim)
			keys[i].ft(player);
		i++;
	}
}

static void	ft_move_up(t_player *player)
{
	player->pos.y -= 1;
}

static void	ft_move_down(t_player *player)
{
	player->pos.y += 1;
}

static void	ft_move_left(t_player *player)
{
	player->pos.x -= 1;
}

static void	ft_move_right(t_player *player)
{
	player->pos.x += 1;
}
