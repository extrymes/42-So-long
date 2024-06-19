NAME = so_long

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

HDR_DIR = includes

MINILIBX_DIR = /home/sabras/sgoinfre/minilibx
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11

LIBFT_DIR = libft
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/,$(LIBFT_FILE))

CFLAGS = -Wall -Wextra -Werror
CC = cc $(CFLAGS) -g -I $(HDR_DIR)

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

%.o: %.c
	@$(CC) -c $< -o $@
	@echo "$(GRAY)Compiled: $<$(RESET)"

all: $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Building libft..$(RESET)"
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "$(GREEN)Library $(LIBFT_FILE) successfully built!$(RESET)"

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -lm -o $(NAME) $^ $(MINILIBX_FLAGS)
	@echo "$(GREEN)Executable $(NAME) successfully created!$(RESET)"

clean:
	@echo "$(BLUE)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Cleaning complete!$(RESET)"

fclean: clean
	@echo "$(BLUE)Complete cleanup, delete $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Cleaning complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
