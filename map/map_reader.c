/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:14:13 by sabras            #+#    #+#             */
/*   Updated: 2024/06/19 06:20:18 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"

static char	**ft_realloc_map(char **map_tab, int size);
static int	ft_check_file(char *file);
static void	ft_remove_nl(char **line);

char	**ft_read_map(char *file)
{
	char	**map_tab;
	int		fd;
	int		i;

	if (!ft_check_file(file))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_print_error("Unable to read file"), NULL);
	map_tab = NULL;
	i = 0;
	while (1)
	{
		map_tab = ft_realloc_map(map_tab, i);
		if (!map_tab)
			return (close(fd), NULL);
		map_tab[i] = get_next_line(fd);
		if (!map_tab[i])
			break ;
		ft_remove_nl(&map_tab[i]);
		i++;
	}
	return (close(fd), map_tab);
}

static char	**ft_realloc_map(char **map_tab, int size)
{
	char	**new_map;
	int		i;

	new_map = malloc((size + 1) * sizeof(char *));
	if (!new_map)
		return (ft_free_map(map_tab, size), NULL);
	i = 0;
	while (i < size)
	{
		new_map[i] = ft_strdup(map_tab[i]);
		if (!new_map[i])
			return (ft_free_map(map_tab, size), ft_free_map(new_map, i), NULL);
		i++;
	}
	return (ft_free_map(map_tab, size), new_map);
}

static int	ft_check_file(char *file)
{
	int	len;

	if (!file)
		return (ft_print_error("File does not exist"), 0);
	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (file[len - 4] != '.' || file[len - 3] != 'b'
		|| (file[len - 2] != 'e' || file[len - 1] != 'r'))
		return (ft_print_error("Invalid file extension"), 0);
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
