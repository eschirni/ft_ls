# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 14:38:22 by eschirni          #+#    #+#              #
#    Updated: 2025/03/09 18:14:07 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "ft_ls" #fix relinking
FILES = src/main.c src/sorting.c src/flags.c
OBJS = $(FILES:.c=.o)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@

all: $(OBJS)
	@cd src/libft && make
	gcc -Wall -Wextra -Werror -Ofast $(OBJS) src/libft/libft.a -o $(NAME)
	
clean:
	@rm -f $(OBJS)
	@cd src/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd src/libft && make fclean

re: fclean all
