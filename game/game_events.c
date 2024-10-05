/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:09:48 by sabras            #+#    #+#             */
/*   Updated: 2024/10/05 15:57:24 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_handle_keypress(int keysym, t_game *game);
static int	ft_handle_destroy(t_game *game);

void	ft_handle_events(t_game game)
{
	mlx_hook(game.win_ptr, KEYPRESS, KEYPRESSMASK, &ft_handle_keypress, &game);
	mlx_hook(game.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK,
		&ft_handle_destroy, &game);
	mlx_loop(game.mlx_ptr);
}

static int	ft_handle_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		ft_destroy_game(*game, 0);
	else if (ft_player_move(&game->player, game->map.tab, keysym))
	{
		ft_move_enemies(game->map.tab);
		ft_check_player_pos(game->map.tab, &game->player, game);
		ft_render_map(game->map.tab, *game);
	}
	return (0);
}

static int	ft_handle_destroy(t_game *game)
{
	ft_destroy_game(*game, 0);
	return (0);
}
