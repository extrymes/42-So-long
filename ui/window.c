/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:52:50 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 01:31:19 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/colors.h"

static void			ft_calculate_win_size(char **map, t_game_data *game);
static t_img_data	ft_load_image(t_game_data game, char *filename);

void	ft_new_window(char **map, t_game_data *game)
{
	ft_calculate_win_size(map, game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width,
			game->win_height, WIN_TITLE);
	if (!game->win_ptr)
	{
		ft_print_error("Failed to create window");
		ft_destroy_game(*game);
	}
	game->player_img = ft_load_image(*game, PLAYER_PATH);
	game->exit_img = ft_load_image(*game, EXIT_PATH);
	game->collec_img = ft_load_image(*game, COLLEC_PATH);
	game->wall_img = ft_load_image(*game, WALL_PATH);
	game->space_img = ft_load_image(*game, SPACE_PATH);
}

static t_img_data	ft_load_image(t_game_data game, char *filename)
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

static void	ft_calculate_win_size(char **map, t_game_data *game)
{
	int	i;

	game->win_width = 0;
	i = 0;
	while (map[0][i++])
		game->win_width += SPRITE_SIZE;
	game->win_height = 0;
	i = 0;
	while (map[i++])
		game->win_height += SPRITE_SIZE;
}

void	ft_destroy_game(t_game_data game)
{
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	ft_free_map(game.map);
	exit(0);
}
