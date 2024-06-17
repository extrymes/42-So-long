/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:18:49 by sabras            #+#    #+#             */
/*   Updated: 2024/06/17 13:30:24 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_game(t_game_data game, int status)
{
	ft_destroy_images(game);
	if (game.win_ptr)
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	if (game.mlx_ptr)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
	}
	ft_free_map(game.map, -1);
	exit(status);
}
