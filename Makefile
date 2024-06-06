NAME = so_long

SRCS = 	so_long.c

UTIL_DIR = utils
UTIL_FILES = structs.c map_reader.c map_checkers.c map_utils.c
UTIL_SRCS = $(addprefix $(UTIL_DIR)/,$(UTIL_FILES))

OBJS = $(SRCS:.c=.o) $(UTIL_SRCS:.c=.o)

HDR_DIR = includes

LIBFT_DIR = libft
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR)/,$(LIBFT_FILE))

CFLAGS = -Wall -Wextra -Werror
CC = cc $(CFLAGS) -I $(HDR_DIR)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $^ $(LIBFT)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
