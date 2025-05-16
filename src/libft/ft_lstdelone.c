/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:43:48 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/22 19:54:16 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdelone(t_list *lst)
{
	free(lst->content);
	free(lst->path);
	free(lst->s_nlink);
	free(lst->s_name);
	free(lst->s_group);
	free(lst->s_size);
	free(lst);
}
