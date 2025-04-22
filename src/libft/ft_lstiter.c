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

void	ft_lstiter(t_list *lst, void (*f)(const char *, const char *), const char *flags)
{
	write(1, "\n", 1);
	f(lst->content, flags);
	if (lst->next != NULL)
		ft_lstiter(lst->next, f, flags);
}
