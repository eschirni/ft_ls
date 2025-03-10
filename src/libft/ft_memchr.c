/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:54:40 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/22 19:54:37 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*string;
	size_t		i;

	string = s;
	i = 0;
	while (i < n)
	{
		if (string[i] == c)
			return ((void *)&string[i]);
		i++;
	}
	return (NULL);
}
