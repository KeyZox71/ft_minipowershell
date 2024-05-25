/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:06:24 by mmoussou          #+#    #+#             */
/*   Updated: 2024/05/25 14:24:29 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>

/* INT */

int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_abs(int n);

/* CHAR */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

/* MEMORY */

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t n, size_t elsize);

void		ft_free(const char *str, ...);

/* INT & ARG */

int			ft_atoi(const char *str);
long long	ft_atol(const char *str);
char		*ft_itoa(int n);
char		*ft_ltoa(long long n);

/* STRINGS */

uint		ft_strlen(char const *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strjoin_free_s1(char *s1, const char *s2);
char		*ft_strjoin_free_s2(const char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

char		*ft_itoa(int n);
char		**ft_split(const char *str, char ch);
char		*ft_substr(char const *s, unsigned int start, size_t len);

int			ft_toupper(int c);
int			ft_tolower(int c);

/* FD PUT FUNC */

int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
int			ft_putuhex_fd(unsigned long long nbr, char *base, int fd);

int			ft_printf(const char *str, ...);
int			ft_printf_fd(int fd, const char *str, ...);

// ---------------- LINKED LISTS ---------------- //

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* LISTS */

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
uint		ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_stack
{
	int				nb_init;
	int				nb;
	struct s_stack	*next;
}					t_stack;

/* ------ STACK UTILS ------ */

t_stack		*ft_stacknew(int content);
uint		ft_stacksize(t_stack *stack);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackadd_front(t_stack **stack, t_stack *new);

/* ----- GET_NEXT_LINE ------ */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);

#endif
