/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:41:53 by eschirni          #+#    #+#             */
/*   Updated: 2025/03/09 19:49:16 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

void swap(char **first, char **second)
{
	char *tmp = *first;
	*first = *second;
	*second = tmp;
}

int sort_one(unsigned short min, unsigned short max, char **argv)
{
	unsigned short i = min;

	while (i < max)
	{
		while (ft_strcmp(argv[i], argv[max]) < 1 && i <= max - 1)
			i++;
		while (ft_strcmp(argv[max], argv[i]) > 0 && max >= min + 1)
			max--;
		if (ft_strcmp(argv[i], argv[max]) > 0)
			swap(&argv[i], &argv[max]);
	}

	return (max);
}

void sort_argv(unsigned short min, unsigned short max, char **argv)
{
	if (min < max) //to stop recursion
	{
		unsigned short pivot = sort_one(min, max, argv);
		sort_argv(min, pivot -1, argv);
		sort_argv(pivot +1, max, argv);
	}
}

void lst_swap(t_list *first, t_list *second)
{
	char *tmp_content = first->content;
    unsigned char tmp_type = first->type;

	first->content = second->content;
	first->type = second->type;

	second->content = tmp_content;
	second->type = tmp_type;
}

int sort_one_lst(unsigned int min, unsigned int max, t_list *lst)
{
	unsigned int i = min;
	t_list *lst_min = ft_lstfind(lst, min);
	t_list *lst_max = ft_lstfind(lst, max); //SEGFAULT

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
			lst_swap(lst_min, lst_max);
	}

	return (max);
}

void sort_list(unsigned int min, unsigned int max, t_list *lst)
{
	if (min < max) //to stop recursion
	{
		unsigned int pivot = sort_one_lst(min, max, lst);
		sort_list(min, pivot -1, lst);
		sort_list(pivot +1, max, lst);
	}
}
