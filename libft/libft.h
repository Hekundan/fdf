/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johartma <johartma@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:17:50 by johartma          #+#    #+#             */
/*   Updated: 2025/04/16 12:17:44 by johartma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H 
# define LIBFT_H
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>


int				ft_printf(const char *fmt, ...);
int				ft_printf_c(const char c);
int				ft_printf_s(const char *s);
int				ft_printf_p(const void *p);
int				ft_printf_i(const int i);
int				ft_printf_u(const unsigned int u);
int				ft_printf_x(const unsigned int x);
int				ft_printf_xx(const unsigned int xx);
int				ft_printf_per(void);
void			ft_putchar(char c);
void			ft_putnbr_flex(ssize_t nb, int *count, int base_length);
void			ft_putnbr_p(uintptr_t nb, int *count, int base_length);
void			ft_putnbr_flex_x(unsigned int nb, int *count, int base_length);
int				ft_atoi(const char *str);
void			*ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int nb);
void			*ft_memchr(const void *s, int c, int n);
void			*ft_memcpy(void *dest, const void *src, int n);
void			*ft_memmove(void *dest, const void *src, int n);
void			*ft_memset(void *s, int c, int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *str, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *src);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			**ft_split(char const *s, char c);
char			*get_next_line(int fd);
char			*cleanup(char **buffer, char **to_return);
void			ft_copy(const char *src, char *dest, size_t start, size_t len);
ssize_t			read_to_buf(int fd, char **buffer);
size_t			get_len(char *c);
size_t			get_buf_len(char *c);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#endif
