NAME_PROGRAMM = window_mngmt_test

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

INCLUDES    = -I../../libminilibx
LDFLAGS     = -L../../libminilibx -lmlx -lXext -lX11 -lm -lz

SRCS_PROGRAMM = window_management_test.c \
window_management.c

OBJS_PROGRAMM = $(SRCS_PROGRAMM:.c=.o)

all: $(NAME_PROGRAMM)

$(NAME_PROGRAMM): $(OBJS_PROGRAMM)
	$(CC) $(CFLAGS) $(OBJS_PROGRAMM) $(LDFLAGS) -o $(NAME_PROGRAMM)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_PROGRAMM)

fclean: clean
	rm -f $(NAME_PROGRAMM)

re: fclean all