#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshudria <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/22 15:23:21 by oshudria          #+#    #+#              #
#    Updated: 2016/12/22 16:12:01 by oshudria         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
CFLAGS = -Wall -Wextra -Werror
SOURCEDIR = ./srcs/
SRC = ./srcs/fillit.c \
	./srcs/ft_build_matrix.c \
	./srcs/ft_check_free_space.c \
	./srcs/ft_input.c \
	./srcs/ft_output.c \
	./srcs/ft_puterror.c \
	./srcs/ft_solve.c \
	./srcs/ft_t_check.c

INCLUDES = ./includes

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc -o $(NAME) $(CFLAGS) $(SRC) ./libft/libft.a -I $(INCLUDES)

%.o:./%.c
	gcc $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	make clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all
