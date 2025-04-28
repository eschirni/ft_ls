/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:41:53 by eschirni          #+#    #+#             */
/*   Updated: 2025/04/25 19:49:16 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"
#include <sys/stat.h>

time_t get_time(t_list *lst, const char *path)
{
	struct stat stats;
	char *tmp = get_path(lst, path);

	lstat(tmp, &stats);
	free(tmp);

	return (stats.st_mtime);
}

unsigned int sort_one_time_rev(t_list *lst, const char *path, unsigned int min, unsigned int max)
{
	unsigned int i = min;
	t_list *lst_min = ft_lstfind(lst, min);
	t_list *lst_max = ft_lstfind(lst, max);
	time_t min_time = get_time(lst_min, path);
	time_t max_time = get_time(lst_max, path);

	while (i < max)
	{
		while (min_time <= max_time && i <= max - 1)
		{
			lst_min = ft_lstnext(lst_min);
			min_time = get_time(lst_min, path);
			i++;
		}
		while (max_time > min_time && max >= min + 1)
		{
			lst_max = ft_lstprev(lst_max);
			max_time = get_time(lst_max, path);
			max--;
		}
		if (min_time > max_time)
		{
			ft_lstswap(lst_min, lst_max);
			min_time = get_time(lst_min, path);
			max_time = get_time(lst_max, path);
		}
	}

	return (max);
}

unsigned int sort_one_time(t_list *lst, const char *path, unsigned int min, unsigned int max) //could be optimized by storing the time in the list
{
	unsigned int i = min;
	t_list *lst_min = ft_lstfind(lst, min);
	t_list *lst_max = ft_lstfind(lst, max);
	time_t min_time = get_time(lst_min, path);
	time_t max_time = get_time(lst_max, path);

	while (i < max)
	{
		while (min_time >= max_time && i <= max - 1)
		{
			lst_min = ft_lstnext(lst_min);
			min_time = get_time(lst_min, path);
			i++;
		}
		while (max_time < min_time && max >= min + 1)
		{
			lst_max = ft_lstprev(lst_max);
			max_time = get_time(lst_max, path);
			max--;
		}
		if (min_time < max_time)
		{
			ft_lstswap(lst_min, lst_max);
			min_time = get_time(lst_min, path);
			max_time = get_time(lst_max, path);
		}
	}

	return (max);
}

void sort_time(t_list *lst, const char *path, unsigned int min, unsigned int max, unsigned int (*sort_one)(t_list *, const char *, unsigned int, unsigned int)) //no tiebraker to sort like real ls (can't expect that cmon)
{
	if (min < max) //to stop recursion
	{
		unsigned int pivot = sort_one(lst, path, min, max);
		sort_time(lst, path, min, pivot -1, sort_one);
		sort_time(lst, path, pivot +1, max, sort_one);
	}
}

unsigned int sort_one_alpha_rev(t_list *lst, unsigned int min, unsigned int max)
{
	unsigned int i = min;
	t_list *lst_min = ft_lstfind(lst, min);
	t_list *lst_max = ft_lstfind(lst, max);

	while (i < max)
	{
		while (ft_strcmp(lst_min->content, lst_max->content) >= 0 && i <= max - 1)
		{
			lst_min = ft_lstnext(lst_min);
			i++;
		}
		while (ft_strcmp(lst_max->content, lst_min->content) < 0 && max >= min + 1)
		{
			lst_max = ft_lstprev(lst_max);
			max--;
		}
		if (ft_strcmp(lst_min->content, lst_max->content) < 0)
			ft_lstswap(lst_min, lst_max);
	}

	return (max);
}

unsigned int sort_one_alpha(t_list *lst, unsigned int min, unsigned int max)
{
	unsigned int i = min;
	t_list *lst_min = ft_lstfind(lst, min);
	t_list *lst_max = ft_lstfind(lst, max);

	while (i < max)
	{
		while (ft_strcmp(lst_min->content, lst_max->content) < 1 && i <= max - 1)
		{
			lst_min = ft_lstnext(lst_min);
			i++;
		}
		while (ft_strcmp(lst_max->content, lst_min->content) > 0 && max >= min + 1)
		{
			lst_max = ft_lstprev(lst_max);
			max--;
		}
		if (ft_strcmp(lst_min->content, lst_max->content) > 0)
			ft_lstswap(lst_min, lst_max);
	}

	return (max);
}

void sort_alpha(t_list *lst, unsigned int min, unsigned int max, unsigned int (*sort_one)(t_list *, unsigned int, unsigned int))
{
	if (min < max) //to stop recursion
	{
		unsigned int pivot = sort_one(lst, min, max);
		sort_alpha(lst, min, pivot -1, sort_one);
		sort_alpha(lst, pivot +1, max, sort_one);
	}
}

void sort(t_list *lst, const char *flags, const char *path, unsigned int min, unsigned int max)
{
	if (ft_strfindchar(flags, 't') == true)
	{
		if (ft_strfindchar(flags, 'r') == true)
			sort_time(lst, path, min, max, sort_one_time_rev);
		else
			sort_time(lst, path, min, max, sort_one_time);
	}
	else
	{
		if (ft_strfindchar(flags, 'r') == true)
			sort_alpha(lst, min, max, sort_one_alpha_rev);
		else
			sort_alpha(lst, min, max, sort_one_alpha);
	}
}
