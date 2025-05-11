NAME_PROGRAMM = fdf

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -o0

LIBFT_PATH  = lib/libft/
LIBFT       = $(LIBFT_PATH)libft.a
INCLUDES    = -I. -I$(LIBFT_PATH) -Ilib/libminilibx
LDFLAGS     = -L../../libminilibx -lmlx -lXext -lX11 -lm -lz


SRCS_PROGRAMM = src/main.c \
src/parsing/checkers.c \
src/parsing/parse.c \
src/projection/project.c \
src/draw/draw.c \
src/draw/window_management.c

OBJS_PROGRAMM = $(SRCS_PROGRAMM:.c=.o)

all: $(NAME_PROGRAMM)

$(NAME_PROGRAMM): $(OBJS_PROGRAMM) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_PROGRAMM) $(LIBFT) $(INCLUDES) $(LDFLAGS) -o $(NAME_PROGRAMM)

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