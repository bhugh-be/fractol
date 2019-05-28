/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugh-be <bhugh-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:24:02 by bhugh-be          #+#    #+#             */
/*   Updated: 2019/05/28 14:01:06 by bhugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 21
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	char			*content;
	int				fd;
	struct s_file	*next;
}					t_file;

int					ft_atoi(const char *str);
void				ft_bzero(void *src, size_t n);
int					ft_isalnum(int ch);
int					ft_isalpha(int ch);
int					ft_isascii(int ch);
int					ft_isdigit(int ch);
int					ft_isprint(int ch);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
void				*ft_memset(void *buf, int ch, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int ch, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *buf, int ch, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(const char *str, const char *s);
char				*ft_strnstr(const char *str, const char *s, size_t n);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
void				ft_putchar(char c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2, int free_s);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_isspace(int ch);
int					ft_wordcount(const char *str, char c);
size_t				ft_strnlen(const char *str, size_t len);
void				ft_swap(int *a, int *b);
char				*ft_strndup(const char *str, size_t size);
void				ft_bsort(int *arr, int l);
size_t				ft_sqrt(size_t num);
int					ft_max_elem(int arr[], int size);
int					get_next_line(const int fd, char **line);
void				ft_swap_double(double *x, double *y);
t_list				*ft_list_new(void *data);
void				ft_list_add(t_list **begin, void *data);
int					ft_list_count(t_list *begin);
void				ft_list_free(t_list *begin, void (*f)(void *));
int					ft_atoi_base(char *str, int	base);
int					ft_vector_len(char **s);
long int			ft_die(char *error);
long int			ft_max(long int a, long int b);
long int			ft_min(long int a, long int b);
double				round(double n);
double				ipart(double n);
double				fpart(double n);
double				rfpart(double n);

#endif
