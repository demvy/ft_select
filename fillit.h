
#ifndef _FILLIT_H
# define _FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct 	s_square
{
	int 		x_coord;
	int 		y_coord;
	int 		down;
	int 		right;	
}				t_square;


typedef struct  	s_tetramin
{
	char 			letter;
	struct s_square	*first;
	struct s_square	*second;
	struct s_square	*third;
	struct s_square	*fourth;
}					t_tetramin;

#endif