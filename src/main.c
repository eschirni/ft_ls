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

	if (dir != NULL)
	{
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
		write(1, "\n\n", 2);

		if (dirs != NULL && ft_strfindchar(flags, 'R') == true)
			ft_lstiter(dirs, read_dir, flags, path);
		ft_lstclear(&dirs);
		closedir(dir);
	}
	else
		errorexit(false, 1, "ft_ls: cannot access '", path, "': ", strerror(errno));
}

void read_args(t_list *args, const char *flags)
{
	ft_print_unknown(args, flags);

	while (args != NULL)
	{
		if (args->type == DT_DIR)
			read_dir(args->content, flags);
		args = args->next;
	}
}

t_list *probe_args(char **argv, const char *flags, unsigned short flags_count)
{
	DIR *dir;
	t_list *args = NULL;

	for(unsigned short index = 1; argv[index] != NULL; ++index)
	{
		if (argv[index][0] != '-' || (flags_count != 1 && index >= flags_count))
		{
			dir = opendir(argv[index]);
			if (dir != NULL)
				ft_lstadd_back(&args, ft_lstnew(argv[index], DT_DIR, "", flags));
			else if (errno == 20) //20 = is not a dir
				ft_lstadd_back(&args, ft_lstnew(argv[index], DT_UNKNOWN, "", flags)); //UNKNOWN because it might be a link etc
			else
				errorexit(false, 2, "ft_ls: cannot access '", argv[index], "': ", strerror(errno));
			closedir(dir);
		}
	}
	if (args == NULL) //only flags
		read_dir(".", flags);

	return (args);
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
			sort(args, flags, 0, --args_size);
		read_args(args, flags);

		if (flags != NULL)
			free(flags);
		ft_lstclear(&args);
	}
	else if (argc == 0)
		read_dir(".", NULL);
	else
		errorexit(true, 2, "ft_ls: Argument list too long", "", "", "");

	errorexit(true, 0, "", "", "", "");
}
//BUGS:
// -t returns 1?

//TODO:
// right ls -l padding

//BEFORE SUBMIT:
//obviously check for forbidden fucntions like printf or puts I often used for testing
//check for leaks