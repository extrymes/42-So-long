/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabras <sabras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:00:56 by sabras            #+#    #+#             */
/*   Updated: 2024/10/05 15:57:47 by sabras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_TITLE "42-So-long"
# define SPRITE_SIZE 32
# define FLOOR_PATH "textures/floor.xpm"
# define WALL_PATH "textures/box.xpm"
# define COLLEC_PATH "textures/orange.xpm"
# define PLAYER_PATH "textures/player.xpm"
# define EXIT_PATH "textures/portal.xpm"
# define ENEMY_PATH "textures/slime.xpm"
# define FLOOR '0'
# define WALL '1'
# define COLLEC 'C'
# define START 'P'
# define EXIT 'E'
# define ENEMY 'X'
# define ENEMY_MOVE 'M'
# define KEY_ESC XK_Escape
# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_D XK_d
# define KEY_S XK_s
# define KEYPRESS KeyPress
# define KEYPRESSMASK KeyPressMask
# define DESTROYNOTIFY DestroyNotify
# define STRUCTURENOTIFYMASK StructureNotifyMask
# define DESTROY_DISPLAY(mlx_ptr) mlx_destroy_display(mlx_ptr)
# define SET_FONT(mlx_ptr, win_ptr, font) mlx_set_font(mlx_ptr, win_ptr, font)
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char	**tab;
	t_coord	start_pos;
	t_coord	exit_pos;
	int		collectibles;
	int		starts;
	int		exits;
	int		others;
}	t_map;

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
	int	(*ft)(t_player *player, char **map_tab);
}	t_move_keys;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	t_map		map;
	t_player	player;
	t_sprite	floor_spr;
	t_sprite	wall_spr;
	t_sprite	collec_spr;
	t_sprite	player_spr;
	t_sprite	exit_spr;
	t_sprite	enemy_spr;
}	t_game;

// Game structs
t_game		ft_init_game(void);
t_player	ft_new_player(void);
t_coord		ft_new_coord(void);

// Game events
void		ft_handle_events(t_game game);

// Game enemies
void		ft_move_enemies(char **map_tab);

// Game utils
void		ft_destroy_game(t_game game, int status);

// Map reader
char		**ft_read_map(char *file);

// Map data
void		ft_get_map_data(char **map_tab, t_map *map);

// Map chechers
int			ft_check_map(char **map_tab, t_map map);

// Map utils
char		**ft_copy_map(char **map_tab);
void		ft_browse_map(char **map_tab, int x, int y);
void		ft_free_map(char **map_tab, int size);

// Player moves
int			ft_player_move(t_player *player, char **map_tab, int keysym);

// Player utils
void		ft_get_player_pos(char **map_tab, t_player *player);
void		ft_check_player_pos(char **map_tab, t_player *player, t_game *game);

// UI window
void		ft_new_window(char **map_tab, t_game *game);
void		ft_display_hud(t_game game, int moves, int points);

// UI map
void		ft_render_map(char **map_tab, t_game game);
void		ft_update_map(char **map_tab, t_game game, t_coord last_pos);

// UI utils
t_sprite	ft_load_sprite(t_game game, char *filename);
void		ft_destroy_sprites(t_game game);

// Utils printer
void		ft_print_you_win(void);
void		ft_print_you_died(void);
void		ft_print_error(char *error);

#endif
