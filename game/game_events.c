/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:09:48 by sabras            #+#    #+#             */
/*   Updated: 2024/06/13 10:45:46 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_handle_keypress(int keysym, t_game *game);
static int	ft_handle_destroy(t_game *game);

void	ft_handle_events(t_game game)
{
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_handle_destroy, &game);
	mlx_loop(game.mlx_ptr);
}

static int	ft_handle_keypress(int keysym, t_game *game)
{
	t_coord	last_pos;

	last_pos = game->player.pos;
	if (keysym == XK_Escape)
		ft_destroy_game(*game, 0);
	else if (ft_player_move(&game->player, game->map, keysym))
	{
		ft_check_player_pos(&game->player, game);
		ft_render_map(game->map, *game);
	}
	return (0);
}

static int	ft_handle_destroy(t_game *game)
{
	ft_destroy_game(*game, 0);
	return (0);
}
