/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:52:50 by sabras            #+#    #+#             */
/*   Updated: 2024/06/18 14:35:18 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static void	ft_calculate_win_size(char **map, t_game *game);

void	ft_new_window(char **map, t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_print_error("Failed to init mlx"),
			ft_destroy_game(*game, 1));
	ft_calculate_win_size(map, game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width,
			game->win_height, WIN_TITLE);
	if (!game->win_ptr)
		return (ft_print_error("Failed to create window"),
			ft_destroy_game(*game, 1));
	game->floor_img = ft_load_image(*game, FLOOR_PATH);
	game->wall_img = ft_load_image(*game, WALL_PATH);
	game->collec_img = ft_load_image(*game, COLLEC_PATH);
	game->player_img = ft_load_image(*game, PLAYER_PATH);
	game->exit_img = ft_load_image(*game, EXIT_PATH);
	game->enemy_img = ft_load_image(*game, ENEMY_PATH);
}

void	ft_display_hud(t_game game, int moves, int points)
{
	char	*moves_str;
	char	*points_str;
	int		y;

	moves_str = ft_itoa(moves);
	if (!moves_str)
		return (ft_destroy_game(game, 1));
	points_str = ft_itoa(points);
	if (!points_str)
		return (free(moves_str), ft_destroy_game(game, 1));
	y = 0;
	while (game.map[y])
		y++;
	mlx_set_font(game.mlx_ptr, game.win_ptr, "10x20");
	mlx_string_put(game.mlx_ptr, game.win_ptr, 0.5 * SPRITE_SIZE,
		y * SPRITE_SIZE + 22, 0xFFFFFF, "Moves:");
	mlx_string_put(game.mlx_ptr, game.win_ptr, 2.6 * SPRITE_SIZE,
		y * SPRITE_SIZE + 22, 0x47AA89, moves_str);
	free(moves_str);
	mlx_string_put(game.mlx_ptr, game.win_ptr, 4.5 * SPRITE_SIZE,
		y * SPRITE_SIZE + 22, 0xFFFFFF, "Points:");
	mlx_string_put(game.mlx_ptr, game.win_ptr, 6.9 * SPRITE_SIZE,
		y * SPRITE_SIZE + 22, 0xDFDC3E, points_str);
	free(points_str);
}

static void	ft_calculate_win_size(char **map, t_game *game)
{
	int	i;

	game->win_width = 0;
	i = 0;
	while (map[0][i++])
		game->win_width += SPRITE_SIZE;
	game->win_height = 32;
	i = 0;
	while (map[i++])
		game->win_height += SPRITE_SIZE;
}
