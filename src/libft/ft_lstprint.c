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

void print_content(t_list *lst)
{
	if (lst != NULL)
	{
		write(1, lst->content, ft_strlen(lst->content));
		write(1, " ", 1);
		print_content(lst->next);
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

void	ft_lstprint(t_list *lst, const char *flags) //check in lstnew if flags are -l or -m and if so call lstat and save the result
{
	if (ft_strfindchar(flags, 'l') == false)
		print_content(lst);
	else
	{
		print_blocks(lst);
		print_content(lst);
	}
}
