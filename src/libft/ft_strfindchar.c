/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfindchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 10:43:32 by eschirni          #+#    #+#             */
/*   Updated: 2025/03/21 10:46:13 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

bool ft_strfindchar(const char *s, const char c)
{
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == c)
            return (true);
    }
    return (false);
}