NAME = fractol

SRCS =  main.c\
		mandelbrot.c\
		julia.c\
		colors.c\
		draw.c\
		juliahelpfunc.c\
		hooks.c\
		utils.c\
		params.c\
		color_tab.c \
		
B_SRCS = burningship_bonus.c\
		params_bonus.c\
		main.c\
		colors.c\
		draw_bonus.c\
		hooks.c\
		utils.c\
		color_tab.c \
	 
CC = gcc 
MLX = -lmlx -framework OpenGL -framework AppKit 
FLAGS = -Wall -Werror -Wextra
B_OBJ = $(B_SRCS:.c=.o)

$(NAME) :
	$(CC) $(FLAGS) $(MLX) $(SRCS) -o $(NAME)

all : $(NAME)

bonus :
	$(CC) $(FLAGS) $(MLX) $(B_SRCS) -o fractol_b

%.o: %.c
		$(CC)  $(FLAGS) $(MLX) -c $< -o $@

clean :
	rm -f $(NAME)

clean_b :
	rm -f fractol_b

fclean: clean clean_b

re: fclean all

.PHONY: all clean fclean re