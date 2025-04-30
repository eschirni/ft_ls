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

t_list	*ft_lstnew(const char *content, unsigned char type, const char *path, const char *flags)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);

	list->content = ft_strdup(content);
	list->type = type;
	list->path = get_path(list, path);
	list->next = NULL;
	list->prev = NULL;
	if (ft_strfindchar(flags, 'l') == true || ft_strfindchar(flags, 't') == true)
		lstat(list->path, &list->stats);
	return (list);
}
