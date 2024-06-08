/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:08:41 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 12:36:51 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_coord	ft_new_coord(void)
{
	t_coord	pos;

	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_player	ft_new_player(void)
{
	t_player	player;

	player.pos.x = 0;
	player.pos.y = 0;
	player.points = 0;
	return (player);
}
