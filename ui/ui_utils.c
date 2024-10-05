/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:10:40 by sabras            #+#    #+#             */
/*   Updated: 2024/10/04 21:45:12 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	ft_load_sprite(t_game game, char *filename)
{
	t_sprite	sprite;

	sprite.ptr = mlx_xpm_file_to_image(game.mlx_ptr, filename,
			&sprite.width, &sprite.height);
	if (!sprite.ptr)
	{
		ft_print_error("Failed to load image");
		ft_destroy_game(game, 1);
	}
	return (sprite);
}

void	ft_destroy_sprites(t_game game)
{
	if (game.floor_spr.ptr)
		mlx_destroy_image(game.mlx_ptr, game.floor_spr.ptr);
	if (game.wall_spr.ptr)
		mlx_destroy_image(game.mlx_ptr, game.wall_spr.ptr);
	if (game.collec_spr.ptr)
		mlx_destroy_image(game.mlx_ptr, game.collec_spr.ptr);
	if (game.player_spr.ptr)
		mlx_destroy_image(game.mlx_ptr, game.player_spr.ptr);
	if (game.exit_spr.ptr)
		mlx_destroy_image(game.mlx_ptr, game.exit_spr.ptr);
	if (game.enemy_spr.ptr)
		mlx_destroy_image(game.mlx_ptr, game.enemy_spr.ptr);
}
