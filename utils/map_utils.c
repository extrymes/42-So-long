/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:39:17 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 12:32:36 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

char	**ft_copy_map(char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map_copy = malloc((i + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i++])
			return (NULL);
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	ft_browse_map(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	ft_browse_map(map, x, y + 1);
	ft_browse_map(map, x, y - 1);
	ft_browse_map(map, x - 1, y);
	ft_browse_map(map, x + 1, y);
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
