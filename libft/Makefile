CC = cc

CFLAGS = -Wall -Wextra

SRCS = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalpha.c \
ft_isalnum.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_memcmp.c \
ft_printf.c \
conversions_1.c \
conversions_2.c \
helper_functions.c \
get_next_line_utils.c \
get_next_line.c

OBJS = $(SRCS:.c=.o)

OUTPUT = libft.a

HEADER = includes/libft.h

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	ar rcs $(OUTPUT) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXE)

re: fclean all