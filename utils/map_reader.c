/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:14:13 by sabras            #+#    #+#             */
/*   Updated: 2024/06/07 09:10:15 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static int	ft_check_file(char *file);
static void	ft_insert_delimiters(char **map);

char	**ft_read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	if (!ft_check_file(file))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr("Error\nUnable to read file"), NULL);
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i++])
		map[i] = get_next_line(fd);
	ft_insert_delimiters(map);
	return (map);
}

static int	ft_check_file(char *file)
{
	int	i;

	if (!file)
		return (ft_putstr("Error\nFile does not exist"), 0);
	i = ft_strlen(file);
	if (i < 5)
		return (0);
	if (file[i - 4] != '.' || file[i - 3] != 'b'
		|| (file[i - 2] != 'e' || file[i - 1] != 'r'))
		return (ft_putstr("Error\nInvalid file extension"), 0);
	return (1);
}

static void	ft_insert_delimiters(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '\n')
				map[y][x] = '\0';
			x++;
		}
		y++;
	}
}
