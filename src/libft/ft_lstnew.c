/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:09:04 by eschirni          #+#    #+#             */
/*   Updated: 2025/05/19 17:01:32 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <pwd.h>
#include <grp.h>

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
	list->s_nlink = NULL;
	list->s_name = NULL;
	list->s_group = NULL;
	list->s_size = NULL;
	if (ft_strfindchar(flags, 'l') == true || ft_strfindchar(flags, 't') == true)
	{
		lstat(list->path, &list->stats);
		list->s_nlink = ft_itoa(list->stats.st_nlink);
		list->l_nlink = ft_strlen(list->s_nlink);
		list->s_name = ft_strdup(getpwuid(list->stats.st_uid)->pw_name);
		list->l_name = ft_strlen(list->s_name);
		list->s_group = ft_strdup(getgrgid(list->stats.st_gid)->gr_name);
		list->l_group = ft_strlen(list->s_group);
		list->s_size = ft_itoa(list->stats.st_size);
		list->l_size = ft_strlen(list->s_size);
	}
	return (list);
}
