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

NAME = "libft.a"
FILES = ft_isprint.c ft_lstmap.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_atoi.c ft_itoa.c ft_lstnew.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c ft_lstadd_back.c ft_lstsize.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_lstadd_front.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_lstclear.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c ft_lstdelone.c ft_memcpy.c ft_strchr.c ft_strcmp.c ft_isascii.c ft_lstiter.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c ft_lstlast.c ft_memset.c ft_striteri.c ft_strrchr.c ft_straddcharonce.c errorexit.c ft_strfindchar.c
OBJS = $(FILES:.c=.o)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $< -o $@

all: $(OBJS)
	ar rcs libft.a $(OBJS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
