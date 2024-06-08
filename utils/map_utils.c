/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:17 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 02:22:52 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

void	ft_browse_map(char **map, t_map_path *path, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'P')
		path->start = 1;
	else if (map[y][x] == 'E')
		path->exit = 1;
	else if (map[y][x] == 'C')
		path->collectibles++;
	map[y][x] = '1';
	ft_browse_map(map, path, x, y + 1);
	ft_browse_map(map, path, x, y - 1);
	ft_browse_map(map, path, x - 1, y);
	ft_browse_map(map, path, x + 1, y);
}

void	ft_free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
		i++;
	while (i >= 0)
		free((*map)[i--]);
	free(*map);
	*map = NULL;
}
