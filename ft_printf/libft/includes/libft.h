/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrignell <jrignell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:08:35 by jrignell          #+#    #+#             */
/*   Updated: 2020/02/02 17:37:31 by jrignell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 25
# define FD_SIZE 4000
# define FT_ULONG_MAX 18446744073709551615
# define FT_LONG_MAX 9223372036854775807
# define FT_LONG_MIN -9223372036854775808
# define FT_UINT_MAX 4294967295
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648
# define FT_USHRT_MAX 65535
# define FT_SHRT_MAX 32767
# define FT_SHRT_MIN -32768
# define FT_CHAR_MAX 127
# define FT_CHAR_MIN -128
# define FT_UCHAR_MAX 255
# define FT_ABS(x) (x > 0 ? x : -x)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_print_hex(long long int nbr, int upper);
void				ft_print_octal(long long nbr);
void				ft_print_octal_ull(unsigned long long nbr);
int					ft_atoi_base(const char *str, int str_base);
char				*ft_lftoa(long double value, size_t precision);
char				*ft_itoa_base(long long int value, int base, int upper);
char				*ft_itoa_base_u(unsigned long long int value,
					int base, int upper);
void				ft_putnbr_ull_fd(unsigned long long int n, int fd);
void				ft_putnbr_ll_fd(long long n, int fd);
void				ft_print_hex_ull(unsigned long long nbr, int upper);
void				*ft_copy(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isprint(int c);
int					ft_isascii(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long long int n);
void				ft_putnbr_fd(long long int n, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
int					ft_isspace(int c);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
int					get_next_line(const int fd, char **line);

#endif
