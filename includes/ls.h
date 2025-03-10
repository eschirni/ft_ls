/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:20:17 by eschirni          #+#    #+#             */
/*   Updated: 2025/03/09 19:47:28 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <errno.h>
# include <unistd.h>
# include <dirent.h>
# include "../includes/libft.h"

void sort_argv(int min, int max, char **argv);
char	*get_flags(const char *flag);

#endif