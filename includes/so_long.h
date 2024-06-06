/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:00:56 by sabras            #+#    #+#             */
/*   Updated: 2024/06/06 18:06:32 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>

typedef struct s_map_coord
{
	int	x;
	int	y;
}	t_map_coord;

typedef struct s_map_data
{
	t_map_coord	start_pos;
	t_map_coord	exit_pos;
	int			collectibles;
}	t_map_data;

typedef struct s_map_objs
{
	int	starts;
	int	exits;
	int	collectibles;
}	t_map_objs;

char		**ft_read_map(char *file);
t_map_data	ft_get_map_data(char **map);
t_map_coord	ft_new_map_coord(void);
t_map_objs	ft_new_map_objs(void);
int			ft_check_map(char **map);

#endif
