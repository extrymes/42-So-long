/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:17 by sabras            #+#    #+#             */
/*   Updated: 2024/10/04 21:27:27 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

char	**ft_copy_map(char **map_tab)
{
	char	**map_copy;
	int		i;

	i = 0;
	while (map_tab[i])
		i++;
	map_copy = malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (ft_free_map(map_tab, -1), NULL);
	i = 0;
	while (map_tab[i])
	{
		map_copy[i] = ft_strdup(map_tab[i]);
		if (!map_copy[i])
			return (ft_free_map(map_tab, -1), ft_free_map(map_copy, i), NULL);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	ft_browse_map(char **map_tab, int x, int y)
{
	if (map_tab[y][x] == WALL || map_tab[y][x] == ENEMY)
		return ;
	map_tab[y][x] = WALL;
	ft_browse_map(map_tab, x, y + 1);
	ft_browse_map(map_tab, x, y - 1);
	ft_browse_map(map_tab, x - 1, y);
	ft_browse_map(map_tab, x + 1, y);
}

void	ft_free_map(char **map_tab, int size)
{
	int	i;

	if (!map_tab)
		return ;
	i = 0;
	while ((size != -1 && i < size) || (size == -1 && map_tab[i]))
		free(map_tab[i++]);
	free(map_tab);
}
