/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddcharonce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:07:13 by eschirni          #+#    #+#             */
/*   Updated: 2025/03/09 19:22:31 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../../includes/libft.h"

char *ft_straddcharonce(char *s1, const char c)
{
	static bool included[116];

	if (included[(unsigned char)c] == false)
	{
		if (s1 != NULL)
		{
			char *tmp = s1;
			unsigned char i = 0;

			s1 = malloc((ft_strlen(tmp) + 2) * sizeof(char));
			if (s1 == NULL)
				errorexit(true, "Malloc error\n", "", "", "");
			while (tmp[i] != '\0')
			{
				s1[i] = tmp[i];
				++i;
			}
			s1[i] = c;
			s1[i + 1] = '\0';
			free(tmp);
		}
		else
		{
			s1 = malloc(sizeof(char) * 2);
			if (s1 == NULL)
				errorexit(true, "Malloc error\n", "", "", "");
			s1[0] = c;
			s1[1] = '\0';
		}
		included[(unsigned char)c] = true;	
	}
	return (s1);
}
