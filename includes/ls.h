/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:20:17 by eschirni          #+#    #+#             */
/*   Updated: 2025/05/16 23:24:38 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <errno.h>
# include "../includes/libft.h"

# define MAX_USHORT 65535

void            sort_argv(unsigned short min, unsigned short max, char **argv);
void            sort(t_list *lst, const char *flags, unsigned int min, unsigned int max);
unsigned short  get_flags(char **args, char **flags);

#endif