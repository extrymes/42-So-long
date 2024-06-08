/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:14:13 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 02:06:48 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static char	**ft_realloc_map(char **map, int size);
static int	ft_check_file(char *file);
static void	ft_remove_nl(char **line);

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
	map = malloc(1);
	i = 0;
	while (1)
	{
		map = ft_realloc_map(map, i);
		if (!map)
			return (NULL);
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		ft_remove_nl(&map[i++]);
	}
	return (map);
}

static char	**ft_realloc_map(char **map, int size)
{
	char	**new_map;
	int		i;

	new_map = malloc((size + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i++])
			return (NULL);
	}
	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
	map = NULL;
	return (new_map);
}

static int	ft_check_file(char *file)
{
	int	len;

	if (!file)
		return (ft_putstr("Error\nFile does not exist"), 0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (file[len - 4] != '.' || file[len - 3] != 'b'
		|| (file[len - 2] != 'e' || file[len - 1] != 'r'))
		return (ft_putstr("Error\nInvalid file extension"), 0);
	return (1);
}

static void	ft_remove_nl(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
			(*line)[i] = '\0';
		i++;
	}
}
