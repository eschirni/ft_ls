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
	struct dirent *entry;
	t_list *dirs = NULL;
	unsigned int argc = 0;

	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_strfindchar(flags, 'a') == false && entry->d_name[0] == '.')
			continue ;
		++argc;
		ft_lstadd_back(&dirs, ft_lstnew(entry->d_name, entry->d_type, path, flags));
	}
	if (argc > 1)
		sort(dirs, flags, 0, --argc);

	write(1, path, ft_strlen(path));
	write(1, ":\n", 2);
	ft_lstprint(dirs, flags);
	write(1, "\n", 1);

	if (dirs != NULL && ft_strfindchar(flags, 'R') == true)
		ft_lstiter(dirs, read_dir, flags, path);
	ft_lstclear(&dirs);
	closedir(dir);
}

t_list *probe_args(char **argv, const char *flags, unsigned short index)
{
	DIR *dir;
	t_list *args = NULL;

	while(argv[index] != NULL)
	{
		dir = opendir(argv[index]);
		if (dir != NULL)
			ft_lstadd_back(&args, ft_lstnew(argv[index], DT_DIR, "./", flags));
		else if (errno == 20) //20 = is not a dir
			ft_lstadd_back(&args, ft_lstnew(argv[index], DT_UNKNOWN, "./", flags)); //UNKNOWN because it might be a link etc, need to check for -l
		else //will print permission denied too, but it's faster
			errorexit(false, "ft_ls: cannot access '", argv[index], "': ", strerror(errno));
		closedir(dir);
		++index;
	}

	return (args);
}

void read_args(t_list *args, const char *flags)
{
	if (args == NULL) //if only flags
		read_dir(".", flags);
	else
	{
		t_list *tmp = args;
		while(tmp != NULL)
		{
			if (tmp->type == DT_UNKNOWN)
			{
				write(1, tmp->content, ft_strlen(tmp->content));
				write(1, " ", 1);
			}
			tmp = tmp->next;
		}
		write(1, "\n", 1);
		while (args != NULL)
		{
			if (args->type == DT_DIR)
				read_dir(args->content, flags);
			args = args->next;
		}
	}
}

int	main(int argc, char **argv)
{
	if (--argc > 0 && argc <= MAX_USHORT)
	{
		char *flags = NULL;
		unsigned short flag_count = get_flags(argv, &flags);
		t_list *args = probe_args(argv, flags, flag_count);
		unsigned int args_size = ft_lstsize(args);

		if (args_size > 1)
			sort(args, "", 0, --args_size);
		read_args(args, flags);

		if (flags != NULL)
			free(flags);
		ft_lstclear(&args);
	}
	else if (argc == 0)
		read_dir(".", NULL);
	else
		errorexit(true, "ft_ls: Argument list too long", "", "", "");
}
//Makefile says nothing to be done when changing an printf file
//For 1 dir it shouldn't print the dir
//If one arg throws an error it returns more than 0
//Replace all shorts with ints
// Test -l and -t with links
//obviously check for forbidden fucntions like printf or puts I often used for testing

//BEFORE SUBMIT:
//- check how the ls at 42 sorts the output
//- check for leaks