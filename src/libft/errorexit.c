/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 19:05:43 by eschirni          #+#    #+#             */
/*   Updated: 2025/05/19 15:19:39 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void errorexit(bool do_exit, int i, const char *s1, const char *s2, const char *s3, const char *s4)
{
	static int ret = 0;
	if (i != 0)
		ret = i;

	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	write(2, s4, ft_strlen(s4));
	write(2, "\n", 1);

	if (do_exit == true)
		exit(ret);	
}