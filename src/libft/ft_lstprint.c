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

void print_long(t_list *lst)
{
	while (lst != NULL)
	{
		char *s = ft_itoa(lst->stats.st_nlink);
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		s = getpwuid(lst->stats.st_uid)->pw_name;
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		s = getgrgid(lst->stats.st_gid)->gr_name;
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		s = ft_itoa(lst->stats.st_size);
		write(1, s, ft_strlen(s));
		write(1, "	", 1);
		print_time(lst);
		write(1, lst->content, ft_strlen(lst->content));
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

void print_content(t_list *lst)
{
	if (lst != NULL)
	{
		write(1, lst->content, ft_strlen(lst->content));
		write(1, " ", 1);
		print_content(lst->next);
	}
}

void	ft_lstprint(t_list *lst, const char *flags) //check in lstnew if flags are -l or -m and if so call lstat and save the result
{
	if (ft_strfindchar(flags, 'l') == false)
		print_content(lst);
	else
	{
		print_blocks(lst);
		print_long(lst);
	}
}
