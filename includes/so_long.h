/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:00:56 by sabras            #+#    #+#             */
/*   Updated: 2024/06/16 14:27:26 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_TITLE "42-So-long"
# define SPRITE_SIZE 32
# define PLAYER_PATH "textures/player.xpm"
# define EXIT_PATH "textures/portal.xpm"
# define COLLEC_PATH "textures/cristal1.xpm"
# define WALL_PATH "textures/wall.xpm"
# define SPACE_PATH "textures/space.xpm"
# include </home/sabras/sgoinfre/minilibx/mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdlib.h>

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

typedef struct s_map_objs
{
	int	starts;
	int	exits;
	int	others;
}	t_map_objs;

typedef struct s_player
{
	t_coord	pos;
	int		points;
}	t_player;

typedef struct s_img_data {
	void	*ptr;
	int		width;
	int		height;
}	t_img_data;

typedef struct s_game_data {
	char		**map;
	t_map_data	map_data;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	t_player	player;
	t_img_data	player_img;
	t_img_data	exit_img;
	t_img_data	collec_img;
	t_img_data	wall_img;
	t_img_data	space_img;
}	t_game_data;

typedef struct s_move_keys {
	int		keysim;
	void	(*ft)(t_player *);
}	t_move_keys;

// Map data
t_map_data	ft_get_map_data(char **map);

// Map reader
char		**ft_read_map(char *file);

// Map chechers
int			ft_check_map(char **map, t_map_data map_data);

// Map utils
char		**ft_copy_map(char **map);
void		ft_browse_map(char **map, int x, int y);
void		ft_free_map(char **map);

// Events
void		ft_handle_events(t_game_data game);

// Player moves
void		ft_player_move(int keysim, t_player *player);

// Structs
t_game_data	ft_init_game(void);
t_coord		ft_new_coord(void);
t_map_objs	ft_new_objs(void);
t_player	ft_new_player(void);

// Window
void		ft_new_window(char **map, t_game_data *data);
void		ft_destroy_game(t_game_data game);

// Map
void		ft_draw_map(char **map, t_game_data game);

// Utils
void		ft_print_error(char *error);

#endif
