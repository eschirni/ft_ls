/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:31:54 by eschirni          #+#    #+#             */
/*   Updated: 2025/03/09 19:30:44 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"

char *get_flags(const char *flag)
{
	char *flags = NULL;

	if (flag[0] == '-' && flag[1] != '\0' && (flag[1] != '-' || flag[2] == '-'))
	{
		for (unsigned short i = 1; flag[i] != '\0'; ++i)
		{
			if (flag[i] == 'a' || flag[i] == 'l' || flag[i] == 'r' || flag[i] == 'R' || flag[i] == 't')
				flags = ft_straddcharonce(flags, flag[i]);
			else
				errorexit(true, "ft_ls: illegal option -- ", &flag[i], "\nusage: ft_ls [-Ralrt] [file ...]", ""); //because fprintf would be too easy
		}
	}
	return (flags);
}
