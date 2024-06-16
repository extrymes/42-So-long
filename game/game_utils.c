/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:18:49 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 15:23:59 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_game(t_game_data game)
{
	ft_free_images(game);
	if (game.mlx_ptr && game.win_ptr)
	{
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
		free(game.win_ptr);
		free(game.mlx_ptr);
	}
	if (game.map)
		ft_free_map(game.map);
	exit(0);
}
