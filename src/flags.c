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

bool check_arg(char **flags, char *flag)
{
	if (flag[1] != '-' || flag[2] != '\0')
	{
		for (unsigned short i = 1; flag[i] != '\0'; ++i)
		{
			if (flag[i] == 'a' || flag[i] == 'l' || flag[i] == 'r' || flag[i] == 'R' || flag[i] == 't')
				*flags = ft_straddcharonce(*flags, flag[i]);
			else
			{
				flag[i + 1] = '\0';
				errorexit(true, 2, "ft_ls: illegal option -- '", &flag[i], "'\n", "usage: ft_ls [-Ralrt] [file ...]"); //because fprintf would be too easy
			}
		}
		return (true);
	}
	return (false);
}

unsigned short get_flags(char **args, char **flags)
{
	for(unsigned short i = 1; args[i] != NULL; ++i)
	{
		if (args[i][0] == '-' && args[i][1] != '\0')
		{
			if (check_arg(flags, args[i]) == false) //for -- error messages
				return (++i);
		}
	}

	return (1);
}
