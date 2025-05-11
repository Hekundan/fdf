NAME_PROGRAMM = test_parse

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g -o0

LIBFT_PATH  = ../../lib/libft/
LIBFT       = $(LIBFT_PATH)libft.a
INCLUDES    = -I. -I$(LIBFT_PATH)

SRCS_PROGRAMM = parse.c \
checkers.c \
test_parse.c

OBJS_PROGRAMM = $(SRCS_PROGRAMM:.c=.o)

all: $(NAME_PROGRAMM)

$(NAME_PROGRAMM): $(OBJS_PROGRAMM) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_PROGRAMM) $(LIBFT) $(INCLUDES) -o $(NAME_PROGRAMM)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJS_PROGRAMM)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME_PROGRAMM)
	make fclean -C $(LIBFT_PATH)

re: fclean all