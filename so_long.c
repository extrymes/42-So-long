/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:02:00 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 01:02:35 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

int	main(int ac, char **av)
{
	t_game_data	game;

	if (ac != 2)
		return (ft_print_error("Invalid argument"), 1);
	game.map = ft_read_map(av[1]);
	if (!game.map)
		return (1);
	if (!ft_check_map(game.map, &game.map_data))
		return (1);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (ft_print_error("Mlx init error"), 1);
	ft_new_window(game.map, &game);
	ft_draw_map(game.map, game);
	ft_handle_events(game);
	return (0);
}
