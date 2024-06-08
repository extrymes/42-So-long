/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:00:56 by sabras            #+#    #+#             */
/*   Updated: 2024/06/08 12:37:04 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map_data
{
	t_coord	start_pos;
	t_coord	exit_pos;
	int		collectibles;
}	t_map_data;

typedef struct s_player
{
	t_coord	pos;
	int		points;
}	t_player;

// Map data
t_map_data	ft_get_map_data(char **map);

// Map reader
char		**ft_read_map(char *file);

// Map chechers
int			ft_check_map(char **map, t_map_data *map_data);

// Map utils
char		**ft_copy_map(char **map);
void		ft_browse_map(char **map, int x, int y);
void		ft_free_map(char ***map);

// Structs
t_coord		ft_new_coord(void);
t_player	ft_new_player(void);

#endif
