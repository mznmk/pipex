/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 23:03:49 by mmizuno           #+#    #+#             */
/*   Updated: 2021/06/13 15:58:28 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// ================================= library ================================ //

# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>

// ================================= struct ================================= //

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

// ================================= prototype ============================== //

// --------------- Mandatory Part1 ( Libc functions + alpha ) --------------- //

void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *b, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *b, int c, size_t len);
int		ft_memcmp(const void *b1, const void *b2, size_t len);

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strpbrk(const char *s, const char *accept);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_iscntrl(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);
int		ft_isblank(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t number, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

// ---------------- Mandatory Part2 ( 42 functions + alpha ) ---------------- //

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);
void	ft_putnbr(int n);

// ----------------- Bonus Part ( list functions + alpha ) ------------------ //

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *newlst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstpush_front(t_list **lst, void *data);
void	ft_lstpush_back(t_list **lst, void *data);

t_list	*ft_lstpush_strs(int size, char **strs);
t_list	*ft_lstat(t_list *startlst, unsigned int nbr);
void	ft_lstreverse(t_list **lst);
void	ft_lstiter_if(
			t_list *lst, void (*f)(void *), void *data_ref, int (*cmp)());
t_list	*ft_lstfind(t_list *lst, void *data_ref, int (*cmp)());
void	ft_lstremove_if(t_list **lst,
			void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_lstmerge(t_list **lst1, t_list *lst2);
void	ft_lstsort(t_list **begin_list, int (*cmp)());
void	ft_lstreverse_fun(t_list *lst);
void	ft_lstsorted_insert(t_list **lst, void *content, int (*cmp)());
void	ft_lstsorted_merge(t_list **lst1, t_list *lst2, int (*cmp)());

// ----------------- Extra Part ( other useful functions ) ------------------ //

t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(
			t_btree **root, void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(
			t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);

char	*ft_trim_left(const char *str);
char	*ft_trim_right(const char *str);
char	*ft_trim(const char *str);

#endif
