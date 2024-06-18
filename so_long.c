/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:02:00 by sabras            #+#    #+#             */
/*   Updated: 2024/06/18 01:32:02 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_print_error("Invalid argument"), 1);
	game = ft_init_game();
	game.map = ft_read_map(av[1]);
	if (!game.map)
		return (1);
	game.map_data = ft_get_map_data(game.map);
	if (!ft_check_map(game.map, game.map_data))
		return (ft_destroy_game(game, 1), 1);
	ft_new_window(game.map, &game);
	game.player = ft_new_player();
	ft_get_player_pos(game.map, &game.player);
	ft_render_map(game.map, game);
	ft_handle_events(game);
	return (0);
}
