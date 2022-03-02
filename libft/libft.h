/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:08:08 by ahocine           #+#    #+#             */
/*   Updated: 2021/06/24 19:00:36 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# ifndef _STD_OUT
#  define _STD_OUT	1
# endif

# ifndef _STD_ERR
#  define _STD_ERR	1
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				index;
	struct s_list	*prev;
	int				keep;
}					t_list;

/*	Linked lists	*/
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
t_list	*ft_lstmap(t_list *lst, void *(*f)(int), void (*del)(int));
int		ft_is_sort(t_list *lst);
void	ft_lstprint(t_list *lst);

/*	Mandatory		*/
void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *b, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memccpy(void *dest, const void *src, int c, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
int		ft_strlen(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *big, const char	*little, size_t len);
int		ft_atoi(const char *nb);
void	*ft_calloc(size_t number, size_t len);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *str, char charset);
void	ft_free_all2(char **split);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
