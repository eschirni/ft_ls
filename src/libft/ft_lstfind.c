/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:43:48 by eschirni          #+#    #+#             */
/*   Updated: 2025/04/24 21:50:16 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list  *ft_lstprev(t_list *lst)
{
    return (lst->prev);
}

t_list  *ft_lstnext(t_list *lst)
{
    return (lst->next);
}

t_list  *ft_lstfind(t_list *lst, unsigned int i)
{
    while(i-- > 0)
        lst = lst->next;
    return (lst);
}