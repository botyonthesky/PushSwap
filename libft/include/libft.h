/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:16:22 by tmaillar          #+#    #+#             */
/*   Updated: 2024/03/11 07:38:35 by tmaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "gnl.h"
# include "ft_printf.h"

enum	e_dir
{
	FRONT,
	BACK
};

enum	e_mem
{
	MEM,
	FD
};

typedef struct s_gc
{
	void			*content;
	int				fd;
	struct s_gc		*next;
}				t_gc;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

/*--------------------------------LIBFT-----------------------------*/

/*----------------------Garbage-----------------------------*/

void	ft_gc_addb(t_gc **lst, t_gc *new);
void	ft_gc_addf(t_gc **lst, t_gc *new);
void	ft_gc_clear(t_gc **lst);
t_gc	*ft_gc_last(t_gc *lst);
void	ft_memcheck(t_gc **ptrs, void *p, int side, int is_fd);
t_gc	*ft_gc_new(void *content);

/*---------------------Lst----------------------------------*/

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

/*---------------------Mem----------------------------------*/

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*------------------------------Put--------------------------------*/

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_putstr_p(char *str);

/*-----------------------------Str---------------------------------*/

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*-----------------------------Utils---------------------------------*/

int		ft_atoi(const char *nptr);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_swap(int *a, int *b);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
