/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:04:52 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 15:16:54 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_map(char **map, t_game_data game)
{
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
					game.space_img.ptr, x, y);
			if (map[y][x] == '1')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
					game.wall_img.ptr, x, y);
			x++;
		}
		y++;
	}
}
