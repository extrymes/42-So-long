/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:18:49 by sabras            #+#    #+#             */
/*   Updated: 2024/10/04 21:44:44 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_game(t_game game, int status)
{
	ft_destroy_sprites(game);
	if (game.win_ptr)
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	if (game.mlx_ptr)
	{
		DESTROY_DISPLAY(game.mlx_ptr);
		free(game.mlx_ptr);
	}
	ft_free_map(game.map.tab, -1);
	exit(status);
}
