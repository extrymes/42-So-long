NAME = so_long
MACOS = so_long_macos

GAME_DIR = game
MAP_DIR = map
PLAYER_DIR = player
UI_DIR = ui
UTIL_DIR = utils
BIN_DIR = bin

GAME_FILES = game_events.c game_enemies.c game_structs.c game_utils.c
MAP_FILES = map_reader.c map_data.c map_checkers.c map_utils.c
PLAYER_FILES = player_moves.c player_utils.c
UI_FILES = ui_window.c ui_map.c ui_utils.c
UTIL_FILES = utils_printer.c

SRCS = 	so_long.c \
	$(addprefix $(GAME_DIR)/,$(GAME_FILES)) \
	$(addprefix $(MAP_DIR)/,$(MAP_FILES)) \
	$(addprefix $(PLAYER_DIR)/,$(PLAYER_FILES)) \
	$(addprefix $(UI_DIR)/,$(UI_FILES)) \
	$(addprefix $(UTIL_DIR)/,$(UTIL_FILES))

OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

MLX_LINUX = mlx_linux/libmlx.a
MLX_MACOS = mlx_macos/libmlx.a
LIBFT = libft/libft.a

MLX_LINUX_FLAGS = -L mlx_linux -l mlx -l Xext -l X11
MLX_MACOS_FLAGS = -L mlx_macos -l mlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror -g
CC = cc $(CFLAGS)

INCLUDES = -I includes

BOLD = \033[1m
GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
RESET = \033[0m

$(MLX_LINUX):
	@echo "$(YELLOW)Building minilibx...$(RESET)"
	@make -s -C mlx_linux
	@echo "$(GREEN)Building complete!$(RESET)"

$(MLX_MACOS):
	@echo "$(YELLOW)Building minilibx...$(RESET)"
	@make -s -C mlx_macos
	@echo "$(GREEN)Building complete!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make -s -C libft
	@echo "$(GREEN)Building complete!$(RESET)"

$(BIN_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "\n$(YELLOW)Linking objects...$(RESET)"
	@$(CC) -lm -o $(NAME) $^ $(MLX_LINUX_FLAGS)
	@echo "$(BLUE)Progress: 100%$(RESET)"
	@echo "$(GREEN)Compilation complete!$(RESET)"
	@echo "\n\
	█▀▀ █▀▀█  $(YELLOW)█░░ █▀▀█ █▀▀▄ █▀▀▀$(RESET)\n\
	▀▀█ █░░█  $(YELLOW)█░░ █░░█ █░░█ █░▀█$(RESET)\n\
	▀▀▀ ▀▀▀▀  $(YELLOW)▀▀▀ ▀▀▀▀ ▀░░▀ ▀▀▀▀$(RESET)\n"

$(MACOS): $(OBJS) $(LIBFT)
	@echo "\n$(YELLOW)Linking objects...$(RESET)"
	@$(CC) -lm -o $(MACOS) $^ $(MLX_MACOS_FLAGS)
	@echo "$(BLUE)Progress: 100%$(RESET)"
	@echo "$(GREEN)Compilation complete!$(RESET)"
	@echo "\n\
	█▀▀ █▀▀█  $(YELLOW)█░░ █▀▀█ █▀▀▄ █▀▀▀$(RESET)\n\
	▀▀█ █░░█  $(YELLOW)█░░ █░░█ █░░█ █░▀█$(RESET)\n\
	▀▀▀ ▀▀▀▀  $(YELLOW)▀▀▀ ▀▀▀▀ ▀░░▀ ▀▀▀▀$(RESET)\n"

all: INCLUDES += -I mlx_linux -I includes/linux_includes
macos: INCLUDES += -I mlx_macos -I includes/macos_includes

all: $(MLX_LINUX) $(LIBFT) $(NAME)
macos: $(MLX_MACOS) $(LIBFT) $(MACOS)

clean:
	@echo "$(BLUE)Cleaning objects...$(RESET)"
	@rm -rf $(BIN_DIR)
	@make clean -s -C mlx_linux
	@make clean -s -C mlx_macos
	@make clean -s -C libft
	@echo "$(GREEN)Cleaning complete!$(RESET)"

fclean: clean
	@echo "$(BLUE)Complete cleanup..."
	@rm -f $(NAME) $(MACOS)
	@make fclean -s -C libft
	@echo "$(GREEN)Cleaning complete!$(RESET)"

re: fclean all
re_macos: fclean macos

.PHONY: all clean fclean re macos re_macos
