/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:11:02 by eschirni          #+#    #+#             */
/*   Updated: 2025/04/23 14:20:17 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_link(t_list *lst)
{
	write(1, lst->content, ft_strlen(lst->content));
	if (S_ISLNK(lst->stats.st_mode))
	{
		char link[PATH_MAX + 1];
		ssize_t i = readlink(lst->path, link, PATH_MAX);
		if (i > 0)
		{
			link[i] = '\0';
			write(1, " -> ", 4);
			write(1, link, ft_strlen(link));
		}
	}
}

void write_string_part(char *s, unsigned int start, unsigned int end)
{
	while (s[start] != '\0' && start <= end)
	{
		write(1, &s[start], 1);
		++start;
	}
}

void print_time(t_list *lst)
{
	char *s_now = ctime(&lst->stats.st_mtime);
	time_t now = time(NULL);
	time_t diff = now - lst->stats.st_mtime;

	write_string_part(s_now, 4, 6); //month
	write(1, "	", 1);
	write_string_part(s_now, 8, 9); //day
	write(1, "	", 1);
	if (diff <= 15811200 && diff >= 0) //15811200 = 183 days in seconds
	{
		write_string_part(s_now, 11, 15); //time
		write(1, "	", 1);
	}
	else
	{
		write_string_part(s_now, 20, 23); //year
		write(1, "	", 1);
	}
}

void print_perm(t_list *lst)
{
	if (S_ISDIR(lst->stats.st_mode)) //dir
		write(1, "d", 1);
    else if (S_ISLNK(lst->stats.st_mode)) //link
		write(1, "l", 1);
    else if (S_ISCHR(lst->stats.st_mode)) //char special file
		write(1, "c", 1);
    else if (S_ISBLK(lst->stats.st_mode)) //block special file
		write(1, "b", 1);
    else if (S_ISFIFO(lst->stats.st_mode)) //FIFO (Named pipe)
		write(1, "p", 1);
    else if (S_ISSOCK(lst->stats.st_mode)) //socket
		write(1, "s", 1);
    else
		write(1, "-", 1);

	write(1, (lst->stats.st_mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (lst->stats.st_mode & S_IWUSR) ? "w" : "-", 1);
	write(1, (lst->stats.st_mode & S_IXUSR) ? "x" : "-", 1);
	write(1, (lst->stats.st_mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (lst->stats.st_mode & S_IWGRP) ? "w" : "-", 1);
	write(1, (lst->stats.st_mode & S_IXGRP) ? "x" : "-", 1);
	write(1, (lst->stats.st_mode & S_IROTH) ? "r" : "-", 1);
	write(1, (lst->stats.st_mode & S_IWOTH) ? "w" : "-", 1);
	write(1, (lst->stats.st_mode & S_IXOTH) ? "x" : "-", 1);
	write(1, "	", 1);
}

void print_long(t_list *lst)
{
	while (lst != NULL)
	{
		print_perm(lst);
		char *s = ft_itoa(lst->stats.st_nlink);
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		free(s);
		s = getpwuid(lst->stats.st_uid)->pw_name;
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		s = getgrgid(lst->stats.st_gid)->gr_name;
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		s = ft_itoa(lst->stats.st_size);
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		free(s);
		print_time(lst);
		print_link(lst);
		write(1, "\n", 1);
		lst = lst->next;
	}
}

void print_blocks(t_list *lst)
{
	unsigned long blocks = 0;
	while (lst != NULL)
	{
		blocks += lst->stats.st_blocks;
		lst = lst->next;
	}
	char *print_blocks = ft_itoa(blocks / 2);
	write(1, "total ", 6);
	write(1, print_blocks, ft_strlen(print_blocks));
	write(1, "\n", 1);
}

void print_all(t_list *lst)
{
	if (lst != NULL)
	{
		write(1, lst->content, ft_strlen(lst->content));
		write(1, " ", 1);
		print_all(lst->next);
	}
}

void	ft_print_unknown(t_list *lst, const char *flags)
{
	t_list *tmp = NULL;

	while (lst != NULL)
	{
		if (lst->type == DT_UNKNOWN)
			ft_lstadd_back(&tmp, ft_lstnew(lst->content, lst->type, lst->path, flags));
		lst = lst->next;
	}

	if (ft_strfindchar(flags, 'l') == false)
		print_all(tmp);
	else
		print_long(tmp);

	ft_lstclear(&tmp);
}

void	ft_lstprint(t_list *lst, const char *flags)
{
	if (ft_strfindchar(flags, 'l') == false)
		print_all(lst);
	else
	{
		print_blocks(lst);
		print_long(lst);
	}
}
