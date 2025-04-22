/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:09:04 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/22 19:54:28 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(const char *path, char *item)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);

	list->content = malloc((ft_strlen(path) + ft_strlen(item) + 2) * sizeof(char));
	for (unsigned short s = 0; path[s] != '\0'; ++s)
	{
		list->content[s] = path[s];
		if (path[s + 1] == '\0')
		{
			list->content[++s] = '/';
			for (unsigned short i = 0; item[i] != '\0'; ++i)
				list->content[++s] = item[i];
			list->content[++s] = '\0';
			break ;
		}
	}

	list->next = NULL;
	return (list);
}
