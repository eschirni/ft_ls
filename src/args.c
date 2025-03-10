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

int sort(int min, int max, char **argv)
{
	int i = min;

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

void sort_argv(int min, int max, char **argv)
{
	if (min < max) //to stop recursion
	{
		int pivot = sort(min, max, argv);
		sort_argv(min, pivot -1, argv);
		sort_argv(pivot +1, max, argv);
	}
}
