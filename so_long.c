/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:02:00 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 02:14:38 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "includes/libft.h"

int	main(int ac, char **av)
{
	char		**map;
	t_map_data	map_data;

	if (ac != 2)
		return (ft_putstr("Error\nInvalid argument"), 1);
	map = ft_read_map(av[1]);
	if (!map)
		return (1);
	if (!ft_check_map(map, &map_data))
		return (1);
	return (0);
}
