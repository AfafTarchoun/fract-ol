# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 17:52:01 by atarchou          #+#    #+#              #
#    Updated: 2022/01/03 17:56:18 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol.a

SRCS =  main.c\
		fractal.c\
		colors.c\
		draw.c\
		helpfulfunc.c\
		hooks.c\
		utils.c

CC = gcc 
FLAGS = -lmlx -framework OpenGL -framework AppKit
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@
		ar rc $(NAME) $@
		ranlib $(NAME)
clean :
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re