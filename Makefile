NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -Iincludes -Ilibft

SRC			=	src/main.c \
				src/parse_args.c \
				src/parse_numbers.c \
				src/parse_utils.c \
				src/error.c \
				src/free.c \
				src/stack_ops.c \
				src/stack_utilis.c \
				src/ops_rotate.c \
				src/ops_rrotate.c \
				src/ops_swap.c \
				src/ops_push.c \

OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
