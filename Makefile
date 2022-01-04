NAME = fractol

SRCS =  main.c\
		mandelbrot.c\
		julia.c\
		colors.c\
		draw.c\
		helpfulfunc.c\
		hooks.c\
		utils.c\
		params.c\
		color_tab.c \
		
B_SRCS = burningship_bonus.c\
		main.c\
		mandelbrot.c\
		julia.c\
		colors.c\
		draw_bonus.c\
		helpfulfunc.c\
		hooks.c\
		utils.c\
		params.c \
		color_tab.c \
	 
CC = gcc 
MLX = -lmlx -framework OpenGL -framework AppKit 
FLAGS = -Wall -Werror -Wextra
B_OBJ = $(B_SRCS:.c=.o)

$(NAME) :
	$(CC) $(FLAGS) $(MLX) $(SRCS) -o $(NAME)

all : $(NAME)

bonus :
	$(CC) $(FLAGS) $(MLX) $(B_SRCS) -o $(NAME)

%.o: %.c
		$(CC)  $(FLAGS) $(MLX) -c $< -o $@

clean :
	rm -f $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re