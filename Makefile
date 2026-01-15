NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	main.c ft_flags.c ft_parse.c ft_stack.c ft_simple_algorithm.c\
	ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c ft_sort_utils.c\
	ft_adaptive_algorithm.c ft_sort_utils_2.c ft_medium_algorithm.c\
	ft_sort_utils_3.c ft_complex_algorithm.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
