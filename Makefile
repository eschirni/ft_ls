# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:38:22 by eschirni          #+#    #+#              #
#    Updated: 2025/05/16 23:53:13 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FILES = src/main.c src/sorting.c src/flags.c
OBJS = $(FILES:.c=.o)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@

all: $(NAME)

src/libft/libft.a:
	@make -C src/libft

$(NAME): $(OBJS) src/libft/libft.a
	gcc -Wall -Wextra -Werror -Ofast $(OBJS) src/libft/libft.a -o $(NAME)
	
clean:
	@rm -f $(OBJS)
	@make -C src/libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C src/libft fclean

re: fclean all
