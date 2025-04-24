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

int sort_one_lst(unsigned int min, unsigned int max, t_list *lst)
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

void sort_list(unsigned int min, unsigned int max, t_list *lst)
{
	if (min < max) //to stop recursion
	{
		unsigned int pivot = sort_one_lst(min, max, lst);
		sort_list(min, pivot -1, lst);
		sort_list(pivot +1, max, lst);
	}
}
