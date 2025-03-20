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

void read_dir(const char *path)
{
	DIR *dir = opendir(path);
	if (dir != NULL)
	{
		struct dirent *entry;
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
		if (dir == NULL && errno != 20) //20 = is not a dir | this will print permission denied too, but it's faster so Imma keep that
			errorexit(false, "ft_ls: cannot access '", args[index], "': ", strerror(errno));
		closedir(dir);
		++index;
	}
}

void read_args(char **args, char *flags)
{
	unsigned short i = 1;
	if (flags != NULL) //get flags count and invalid option -x
		i = 2;

	probe_args(args, i);
	while(args[i] != NULL)
	{
		read_dir(args[i]);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (--argc > 0 && argc <= MAX_USHORT)
	{
		char *flags = get_flags(argv[1]); //fucked up -a -a etc fuuuuck, -- also weird
		
		if (flags == NULL)
			sort_argv(1, argc, argv);
		else
			sort_argv(2, argc, argv);

		read_args(argv, flags);

		if (flags != NULL)
			free(flags);
	}
	else if (argc == 0)
		read_dir(".");
	else
		errorexit(true, "ft_ls: Argument list too long", "", "", "");
	//system("leaks ft_ls"); //install leaks
}
