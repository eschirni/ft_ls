/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:52:30 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/22 19:54:19 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void add_path(t_list *lst, const char *path)
{
	char *tmp = malloc((ft_strlen(path) + ft_strlen(lst->content) + 2) * sizeof(char));
	for (unsigned short s = 0; path[s] != '\0'; ++s)
	{
		tmp[s] = path[s];
		if (path[s + 1] == '\0')
		{
			tmp[++s] = '/';
			for (unsigned short i = 0; lst->content[i] != '\0'; ++i)
				tmp[++s] = lst->content[i];
			tmp[++s] = '\0';
			break ;
		}
	}
	free(lst->content);
	lst->content = tmp;
}

void	ft_lstiter(t_list *lst, void (*f)(const char *, const char *), const char *flags, const char *path)
{
	if(lst->type == DT_DIR && !(lst->content[0] == '.' && (lst->content[1] == '\0' || (lst->content[1] == '.' && lst->content[2] == '\0'))))
	{
		write(1, "\n", 1);
		add_path(lst, path);
		f(lst->content, flags);
	}
	if (lst->next != NULL)
		ft_lstiter(lst->next, f, flags, path);
}
