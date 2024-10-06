NAME = libft.a

BIN_DIR = bin

SRCS = ft_putchar.c ft_putstr.c ft_strlen.c ft_strdup.c \
	ft_itoa.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:%.c=$(BIN_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g
CC = cc $(CFLAGS)

$(BIN_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
