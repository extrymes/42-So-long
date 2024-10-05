NAME = so_long
MACOS = so_long_macos

SRCS = 	so_long.c

GAME_DIR = game
GAME_FILES = game_events.c game_enemies.c game_structs.c game_utils.c
GAME_SRCS = $(addprefix $(GAME_DIR)/,$(GAME_FILES))

MAP_DIR = map
MAP_FILES = map_reader.c map_data.c map_checkers.c map_utils.c
MAP_SRCS = $(addprefix $(MAP_DIR)/,$(MAP_FILES))

PLAYER_DIR = player
PLAYER_FILES = player_moves.c player_utils.c
PLAYER_SRCS = $(addprefix $(PLAYER_DIR)/,$(PLAYER_FILES))

UI_DIR = ui
UI_FILES = ui_window.c ui_map.c ui_utils.c
UI_SRCS = $(addprefix $(UI_DIR)/,$(UI_FILES))

UTIL_DIR = utils
UTIL_FILES = utils_printer.c
UTIL_SRCS = $(addprefix $(UTIL_DIR)/,$(UTIL_FILES))

OBJS = $(SRCS:.c=.o) $(GAME_SRCS:.c=.o) $(MAP_SRCS:.c=.o) \
	$(PLAYER_SRCS:.c=.o) $(UI_SRCS:.c=.o) $(UTIL_SRCS:.c=.o)

MLX_LINUX = mlx_linux/libmlx.a
MLX_MACOS = mlx_macos/libmlx.a

MINILIBX_LINUX_FLAGS = -L mlx_linux -l mlx -l Xext -l X11
MINILIBX_MACOS_FLAGS = -L mlx_macos -l mlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/,$(LIBFT_FILE))

CFLAGS = -Wall -Wextra -Werror
CC = cc $(CFLAGS) -g

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

INCLUDES = -Iincludes

all: INCLUDES += -I mlx_linux -I includes/linux_includes
macos: INCLUDES += -I mlx_macos -I includes/macos_includes

all: $(MLX_LINUX) $(NAME)
macos: $(MLX_MACOS) $(MACOS)

%.o: %.c
	@$(CC) $(INCLUDES) -c $< -o $@
	@echo "$(GRAY)Compiled: $<$(RESET)"

$(MLX_LINUX):
	@echo "$(YELLOW)Building minilibx..$(RESET)"
	@make -s -C mlx_linux

$(MLX_MACOS):
	@echo "$(YELLOW)Building minilibx..$(RESET)"
	@make -s -C mlx_macos

$(LIBFT):
	@echo "$(YELLOW)Building libft..$(RESET)"
	@make -s -C $(LIBFT_DIR)
	@echo "$(GREEN)Library $(LIBFT_FILE) successfully built!$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -lm -o $(NAME) $^ $(MINILIBX_LINUX_FLAGS)
	@echo "$(GREEN)Executable $(NAME) successfully created!$(RESET)"

$(MACOS): $(OBJS) $(LIBFT)
	@$(CC) -lm -o $(MACOS) $^ $(MINILIBX_MACOS_FLAGS)
	@echo "$(GREEN)Executable $(NAME) successfully created!$(RESET)"

clean:
	@echo "$(BLUE)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make clean -s -C mlx_linux
	@make clean -s -C mlx_macos
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Cleaning complete!$(RESET)"

fclean: clean
	@echo "$(BLUE)Complete cleanup, delete $(NAME)...$(RESET)"
	@rm -f $(NAME) $(MACOS)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Cleaning complete!$(RESET)"

re: fclean all
re_macos: fclean macos

.PHONY: all clean fclean re macos re_macos
