/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:39:31 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/22 19:54:09 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *t = *lst;

	if (t == NULL)
		lst[0] = new;
	else
	{
		t_list *tp = t;
		while (t->next != NULL)
		{
			tp = t;
			t = t->next;
		}
		t->next = new;
		t->prev = tp;
	}
}
