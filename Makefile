# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 17:52:01 by atarchou          #+#    #+#              #
#    Updated: 2022/01/04 14:02:47 by atarchou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol.a

SRCS =  main.c\
		mandelbrot.c\
		julia.c\
		colors.c\
		draw.c\
		helpfulfunc.c\
		hooks.c\
		utils.c
B_SRCS = burningship_bonus.c

CC = gcc 
FLAGS = -lmlx -framework OpenGL -framework AppKit

B_OBJ = $(B_SRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)

bonus: $(B_OBJ)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@
		ar rc $(NAME) $@
		ranlib $(NAME)
clean :
	rm -f $(OBJS) $(B_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re