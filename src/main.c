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

void read_dir(const char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL)
		puts (entry->d_name);
	closedir(dir);
}

void read_args(char **args, char *flags)
{
	unsigned short i = 1;
	if (flags != NULL)
		i = 2;

	while(args[i] != NULL)
	{
		read_dir(args[i]);
		++i;
	}
}

int	main(int argc, char **argv) //Directories unable to be openend are printed first and seperately, even with -R
{
	if (--argc > 0)
	{
		char *flags = get_flags(argv[1]);
		
		if (flags == NULL)
			sort_argv(1, argc, argv);
		else
			sort_argv(2, argc, argv);

		read_args(argv, flags);

		if (flags != NULL)
			free(flags);
	}
	else
		read_dir(".");
	//system("leaks ft_ls");
}
