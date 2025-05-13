# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 17:14:13 by eschirni          #+#    #+#              #
#    Updated: 2025/03/09 19:10:04 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = *.c
OBJS = $(FILES:.c=.o)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs libft.a $(OBJS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
