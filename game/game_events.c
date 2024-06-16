/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:09:48 by sabras            #+#    #+#             */
/*   Updated: 2024/06/13 10:45:46 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

static int	ft_handle_keypress(int keysym, t_game_data *game);
static int	ft_handle_keyrelease(int keysym, void *game);
static int	ft_handle_no_event(void *game);

void	ft_handle_events(t_game_data game)
{
	mlx_loop_hook(game.mlx_ptr, &ft_handle_no_event, &game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, &game);
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, &ft_handle_keyrelease,
		&game);
	mlx_loop(game.mlx_ptr);
}

static int	ft_handle_keypress(int keysym, t_game_data *game)
{
	if (keysym == XK_Escape)
		ft_destroy_game(*game);
	printf("Keypress: %d\n", keysym);
	return (0);
}

static int	ft_handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

static int	ft_handle_no_event(void *data)
{
	(void)data;
	return (0);
}
