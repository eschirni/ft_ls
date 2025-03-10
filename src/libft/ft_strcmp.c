/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:31:09 by eschirni          #+#    #+#             */
/*   Updated: 2025/02/27 19:03:52 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
		else if (s1[i] == '\0' || s2[i] == '\0')
			return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
		i++;
	}
	return (0);
}
