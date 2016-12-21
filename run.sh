#!/bin/bash
gcc srcs/fillit.c \
	srcs/ft_build_matrix.c \
	srcs/ft_check_free_space.c \
	srcs/ft_input.c \
	srcs/ft_output.c \
	srcs/ft_puterror.c \
	srcs/ft_t_check.c \
	srcs/ft_solve.c \
	../libft/libft.a \
	-I ./includes/ -o fillit
echo "fillit file crated"
