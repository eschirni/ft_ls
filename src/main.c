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
	if (dir != NULL && errno != 20) //guess something went wrong, permissions etc. I have to handle errors in here too, bec . for example.
	{
		struct dirent *entry;
		t_list *dirs = NULL;
		unsigned int argc = 0;

		while ((entry = readdir(dir)) != NULL)
		{
			if (ft_strfindchar(flags, 'a') == false && entry->d_name[0] == '.')
				continue ;
			++argc;
			ft_lstadd_back(&dirs, ft_lstnew(entry->d_name, entry->d_type));
		}
		sort_list(0, --argc, dirs);

		write(1, path, ft_strlen(path));
		write(1, ":\n", 2);
		ft_lstprint(dirs);
		write(1, "\n", 1);

		if (dirs != NULL && ft_strfindchar(flags, 'R') == true)
			ft_lstiter(dirs, read_dir, flags, path);
		ft_lstclear(&dirs);
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
		for (int i = 0; i < argc; i++)
			puts(argv[i]);
		read_args(argv, flags, flag_count);

		if (flags != NULL)
			free(flags);
	}
	else if (argc == 0)
		read_dir(".", NULL);
	else
		errorexit(true, "ft_ls: Argument list too long", "", "", "");
}
//SEGFAULT on empty dir
//-t might be just the standard unsorted output reversed
//For 1 dir it shouldn't print the dir
//If one arg throws an error it returns -1
//Replace all shorts with ints
//stop relinking Makefile

//BEFORE SUBMIT:
//- check how the ls at 42 sorts the output
//- check for leaks