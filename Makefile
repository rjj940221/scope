NAME = scope
COMFLAGS = -Wall -Werror -Wextra -g3 -w -I ./libft -L./libft -lft
LINKFLAGS =  -framework GLUT -framework OpenGL -framework Cocoa
src = main.c readobj.c read_material.c memory.c

all:
	gcc -o $(NAME) $(COMFLAGS) $(src) $(LINKFLAGS)
