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
    char *tmp_s_nlink = first->s_nlink;
	unsigned int tmp_l_nlink = first->l_nlink;
    char *tmp_s_name = first->s_name;
	unsigned int tmp_l_name = first->l_name;
	char *tmp_s_group = first->s_group;
	unsigned int tmp_l_group = first->l_group;
	char *tmp_s_size = first->s_size;
	unsigned int tmp_l_size = first->l_size;

	first->content = second->content;
	first->type = second->type;
	first->path = second->path;
	first->stats = second->stats;
	first->s_nlink = second->s_nlink;
	first->l_nlink = second->l_nlink;
	first->s_name = second->s_name;
	first->l_name = second->l_name;
	first->s_group = second->s_group;
	first->l_group = second->l_group;
	first->s_size = second->s_size;
	first->l_size = second->l_size;

	second->content = tmp_content;
	second->type = tmp_type;
	second->path = tmp_path;
	second->stats = tmp_stats;
	second->s_nlink = tmp_s_nlink;
	second->l_nlink = tmp_l_nlink;
	second->s_name = tmp_s_name;
	second->l_name = tmp_l_name;
	second->s_group = tmp_s_group;
	second->l_group = tmp_l_group;
	second->s_size = tmp_s_size;
	second->l_size = tmp_l_size;
}
