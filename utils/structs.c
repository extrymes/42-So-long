/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:08:41 by sabras            #+#    #+#             */
/*   Updated: 2024/06/07 11:11:43 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_coord	ft_new_coord(void)
{
	t_coord	map_coord;

	map_coord.x = 0;
	map_coord.y = 0;
	return (map_coord);
}

t_map_objs	ft_new_map_objs(void)
{
	t_map_objs	map_objs;

	map_objs.starts = 0;
	map_objs.exits = 0;
	map_objs.collectibles = 0;
	return (map_objs);
}
