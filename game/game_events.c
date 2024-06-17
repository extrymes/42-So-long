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

static int	ft_handle_keypress(int keysym, t_game_data *game);
static void	ft_check_player_pos(t_player *player, t_game_data *game);

void	ft_handle_events(t_game_data game)
{
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, &game);
	mlx_loop(game.mlx_ptr);
}

static int	ft_handle_keypress(int keysym, t_game_data *game)
{
	if (keysym == XK_Escape)
		ft_destroy_game(*game, 0);
	else if (ft_player_move(&game->player, game->map, keysym))
	{
		ft_check_player_pos(&game->player, game);
		ft_draw_map(game->map, *game);
	}
	return (0);
}

static void	ft_check_player_pos(t_player *player, t_game_data *game)
{
	if (game->map[player->pos.y][player->pos.x] == 'C')
	{
		game->map[player->pos.y][player->pos.x] = '0';
		player->points++;
	}
	if (game->map[player->pos.y][player->pos.x] == 'E'
		&& (player->points == game->map_data.collectibles))
		ft_destroy_game(*game, 0);
}
