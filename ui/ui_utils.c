/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:10:40 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 15:20:27 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img_data	ft_load_image(t_game_data game, char *filename)
{
	t_img_data	img;

	img.ptr = mlx_xpm_file_to_image(game.mlx_ptr, filename,
			&img.width, &img.height);
	if (!img.ptr)
	{
		ft_print_error("Failed to load image");
		ft_destroy_game(game);
	}
	return (img);
}

void	ft_free_images(t_game_data game)
{
	if (game.player_img.ptr)
		free(game.player_img.ptr);
	if (game.exit_img.ptr)
		free(game.exit_img.ptr);
	if (game.collec_img.ptr)
		free(game.collec_img.ptr);
	if (game.wall_img.ptr)
		free(game.wall_img.ptr);
	if (game.space_img.ptr)
		free(game.space_img.ptr);
}
