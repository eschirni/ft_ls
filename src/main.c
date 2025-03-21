/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:31:29 by eschirni          #+#    #+#             */
/*   Updated: 2025/03/09 19:57:32 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ls.h"
#include <string.h>

void read_dir(const char *path, const char *flags)
{
	DIR *dir = opendir(path);
	if (dir != NULL) //guess something went wrong, permissions etc. I have to handle errors in here too, bec . for example.
	{
		struct dirent *entry;
		if (flags != NULL && ft_strfindchar(flags, 'R') == true)
		{
			while ((entry = readdir(dir)) != NULL)
				read_dir(entry->d_name, flags);
		}
		puts(path);
		closedir(dir);
		dir = opendir(path);
		while ((entry = readdir(dir)) != NULL)
			puts (entry->d_name);
	}
	closedir(dir);
}

void probe_args(char **args, unsigned short index) //return array with only valid ones
{
	DIR *dir;

	while(args[index] != NULL)
	{
		dir = opendir(args[index]);
		if (dir == NULL && errno != 20) //20 = is not a dir | will print permission denied too, but it's faster
			errorexit(false, "ft_ls: cannot access '", args[index], "': ", strerror(errno));
		closedir(dir);
		++index;
	}
}

void read_args(char **args, const char *flags, unsigned short flag_count)
{
	if (args[flag_count] == NULL)
		read_dir(".", flags);
	else
	{
		probe_args(args, flag_count);
		while(args[flag_count] != NULL)
		{
			read_dir(args[flag_count], flags);
			++flag_count;
		}
	}
}

int	main(int argc, char **argv)
{
	if (--argc > 0 && argc <= MAX_USHORT)
	{
		char *flags = NULL;
		unsigned short flag_count = get_flags(argv, &flags);

		sort_argv(flag_count, argc, argv);
		read_args(argv, flags, flag_count);

		if (flags != NULL)
			free(flags);
	}
	else if (argc == 0)
		read_dir(".", NULL);
	else
		errorexit(true, "ft_ls: Argument list too long", "", "", "");
}
