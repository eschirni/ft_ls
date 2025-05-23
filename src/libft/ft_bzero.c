/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:57:00 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/22 20:37:55 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void	*s, size_t n)
{
	char	*p;

	p = s;
	while (n > 0)
	{
		p[n - 1] = '\0';
		n--;
	}
}
