/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:10:11 by ablizniu          #+#    #+#             */
/*   Updated: 2018/05/29 18:59:00 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10000

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_alist
{
	char			buff[BUFF_SIZE + 1];
	char			*symbol;
	size_t			size_bytes;
	char			*str;
	size_t			extra;
	size_t			extra2;
	size_t			extra3;
	size_t			len_format;
	size_t			n;
	size_t			i;
	size_t			j;
	size_t			k;
	int				a;
	int				b;
	int				c;
	int				d;
	int				fd;
	char			*tmp_1;
	struct s_alist	*next;
	struct t_list	*list;
	struct s_alist	*prev;
}					t_alist;

void				ft_memjn(void *dst, void *src, size_t from, size_t to);
void				ft_bzero_int(int *tab, unsigned int size);
void				ft_bchr(const void *dst, char chr, size_t len);
size_t				lenght(uintmax_t num, int base);
void				swap(char *str, size_t len);
long int			ft_exponentiation(int num, int exp);
void				*ft_memcpy_end(void *dst, void *src, size_t len);
int					get_next_line(const int fd, char **line);
t_alist				*ft_alist_initialize(t_alist *head, size_t bytes);
void				*ft_realloc(void *src, size_t size);
void				*ft_memjoin(void *s1, size_t s1_size,
					void *s2, size_t s2_size);
char				**ft_neo_its_matrix(int column, int raw);
void				ft_swap_int(int *a, int *b);
void				ft_swap_char(char *a, char *b);
int					ft_doop(int a, const char b, int c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list				*ft_lstnew(void const *content, size_t content_size);
const void			*cpy(unsigned char *d_str1,
unsigned char		*s_str2, size_t len, int sign);
size_t				ft_strnlen(char const *str, size_t len);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strstr(const char *s1, const char *s2);
char				**ft_strsplit(const char *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strnew(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);

#endif
