#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <dirent.h>
# include <sys/stat.h>
# define PATH_MAX 4096

typedef struct s_list
{
	char			*content;
	unsigned char	type;
	char			*path;
	struct stat		stats;
	char			*s_nlink;
	unsigned int	l_nlink;
	char			*s_name;
	unsigned int	l_name;
	char			*s_group;
	unsigned int	l_group;
	char			*s_size;
	unsigned int	l_size;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int		ft_atoi(const char *str);
void	ft_bzero(void	*s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(const char *, const char *), const char *flags, const char *path);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(const char *content, unsigned char type, const char *path, const char *flags);
unsigned int	ft_lstsize(t_list *lst);
t_list  *ft_lstfind(t_list *lst, unsigned int i);
t_list  *ft_lstnext(t_list *lst);
t_list  *ft_lstprev(t_list *lst);
void	ft_print_unknown(t_list *lst, const char *flags);
void	ft_lstprint(t_list *lst, const char *flags);
void	ft_lstswap(t_list *first, t_list *second);
char	*get_path(t_list *lst, const char *path);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);;
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_straddcharonce(char *s1, const char c);
void	errorexit(bool do_exit, int i, const char *s1, const char *s2, const char *s3, const char *s4);
bool	ft_strfindchar(const char *s, const char c);

#endif
