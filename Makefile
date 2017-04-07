NAME = ft_select
CFLAGS = -Wall -Wextra -Werror
SRC = ./src/main.c \
	./src/args_func.c \
	./src/do_func.c \
	./src/helpful.c \
	./src/moves.c \
	./src/show_func.c \
	./src/signals.c \
	./src/tem_func.c \
	./src/ft_printf_fd.c \
	
OBJ = $(SRC:.c=.o)
INCLUDES  = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(CFLAGS) $(SRC) ./libft/libft.a -I $(INCLUDES) -ltermcap

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all