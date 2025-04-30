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
    char *tmp_path = first->path;
    struct stat tmp_stats = first->stats;

	first->content = second->content;
	first->type = second->type;
	first->path = second->path;
	first->stats = second->stats;

	second->content = tmp_content;
	second->type = tmp_type;
	second->path = tmp_path;
	second->stats = tmp_stats;
}
