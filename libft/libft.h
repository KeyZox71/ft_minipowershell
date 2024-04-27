/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:06:03 by adjoly            #+#    #+#             */
/*   Updated: 2024/04/27 17:27:45 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum s_boolean
{
	ERROR = -1,
	FALSE,
	TRUE,
}	t_boolean;

char		*ft_strjoinvaarg(char *src, ...);
long long	ft_atoll(const char	*nptr);
int			ft_atoi(const char	*nptr);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strdup(const char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char	*dst, const char	*src, size_t	size);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_itoa(int n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

char		*get_next_line(int fd);
char		*ft_strjoin_gnl(char *s1, char *s2);
void		*ft_calloc(size_t nmemb, size_t size);

void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbrbase_fd(int n, char *base, int fd);
void		ft_putnbrbase(int n, char *base);
void		ft_putnbr(int n);

int			ft_printf(const char *format, ...);
int			ft_printconversion(char conversion, va_list args);
int			ft_putnbrulong(unsigned int n);
int			ft_putaddr(void *ptr);
int			ft_putstr_p(char *s);
int			ft_putnbrbasep(unsigned long int n, char *base);
int			ft_putnbrbase_pf(unsigned int n, char *base);
int			ft_putchar_p(char c);
int			ft_putnbr_p(int n);
size_t		ft_strlen(const char *s);

void		ft_freearr(void **arr);

#endif
