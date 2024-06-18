/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:00:56 by sabras            #+#    #+#             */
/*   Updated: 2024/06/18 13:31:19 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_TITLE "42-So-long"
# define SPRITE_SIZE 32
# define FLOOR_PATH "textures/floor.xpm"
# define WALL_PATH "textures/box.xpm"
# define COLLEC_PATH "textures/apple.xpm"
# define PLAYER_PATH "textures/player.xpm"
# define EXIT_PATH "textures/portal.xpm"
# define FLOOR '0'
# define WALL '1'
# define COLLEC 'C'
# define START 'P'
# define EXIT 'E'
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
	int		moves;
	int		points;
}	t_player;

typedef struct s_sprite
{
	void	*ptr;
	int		width;
	int		height;
}	t_sprite;

typedef struct s_move_keys
{
	int	keysym;
	int	(*ft)(t_player *player, char **map);
}	t_move_keys;

typedef struct s_game
{
	char		**map;
	t_map_data	map_data;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	t_player	player;
	t_sprite	floor_img;
	t_sprite	wall_img;
	t_sprite	collec_img;
	t_sprite	player_img;
	t_sprite	exit_img;
}	t_game;

// Game structs
t_game		ft_init_game(void);
t_player	ft_new_player(void);
t_coord		ft_new_coord(void);
t_map_objs	ft_new_objs(void);

// Game events
void		ft_handle_events(t_game game);

// Game utils
void		ft_destroy_game(t_game game, int status);

// Map reader
char		**ft_read_map(char *file);

// Map data
t_map_data	ft_get_map_data(char **map);

// Map chechers
int			ft_check_map(char **map, t_map_data map_data);

// Map utils
char		**ft_copy_map(char **map);
void		ft_browse_map(char **map, int x, int y);
void		ft_free_map(char **map, int size);

// Player moves
int			ft_player_move(t_player *player, char **map, int keysym);

// Player utils
void		ft_get_player_pos(char **map, t_player *player);
void		ft_check_player_pos(t_player *player, t_game *game);

// UI window
void		ft_new_window(char **map, t_game *game);
void		ft_display_hud(t_game game, int moves, int points);

// UI map
void		ft_render_map(char **map, t_game game);
void		ft_update_map(char **map, t_game game, t_coord last_pos);

// UI utils
t_sprite	ft_load_image(t_game game, char *filename);
void		ft_destroy_images(t_game game);

// Utils printer
void		ft_print_you_win(void);
void		ft_print_you_lost(void);
void		ft_print_error(char *error);

#endif
