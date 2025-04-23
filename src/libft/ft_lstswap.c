/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:20:35 by eschirni          #+#    #+#             */
/*   Updated: 2025/04/25 00:20:39 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void ft_lstswap(t_list *first, t_list *second)
{
	char *tmp_content = first->content;
    unsigned char tmp_type = first->type;

	first->content = second->content;
	first->type = second->type;

	second->content = tmp_content;
	second->type = tmp_type;
}
