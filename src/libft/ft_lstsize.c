/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:41:09 by eschirni          #+#    #+#             */
/*   Updated: 2025/04/24 15:02:30 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int elements = 0;

	while (lst != NULL)
	{
		++elements;
		lst = lst->next;
	}
	return (elements);
}
