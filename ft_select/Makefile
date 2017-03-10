
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
SRC = ./src/main.c 
	
OBJ = $(SRC:.c=.o)
INCLUDES  = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(CFLAGS) $(SRC) ./libft/libft.a -I $(INCLUDES)

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all