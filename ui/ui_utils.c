/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:10:40 by sabras            #+#    #+#             */
/*   Updated: 2024/06/18 14:35:05 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	ft_load_image(t_game game, char *filename)
{
	t_sprite	img;

	img.ptr = mlx_xpm_file_to_image(game.mlx_ptr, filename,
			&img.width, &img.height);
	if (!img.ptr)
	{
		ft_print_error("Failed to load image");
		ft_destroy_game(game, 1);
	}
	return (img);
}

void	ft_destroy_images(t_game game)
{
	if (game.floor_img.ptr)
		mlx_destroy_image(game.mlx_ptr, game.floor_img.ptr);
	if (game.wall_img.ptr)
		mlx_destroy_image(game.mlx_ptr, game.wall_img.ptr);
	if (game.collec_img.ptr)
		mlx_destroy_image(game.mlx_ptr, game.collec_img.ptr);
	if (game.player_img.ptr)
		mlx_destroy_image(game.mlx_ptr, game.player_img.ptr);
	if (game.exit_img.ptr)
		mlx_destroy_image(game.mlx_ptr, game.exit_img.ptr);
	if (game.enemy_img.ptr)
		mlx_destroy_image(game.mlx_ptr, game.enemy_img.ptr);
}
