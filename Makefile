NAME = scope
COMFLAGS = -Wall -Werror -Wextra -w
LINKFLAGS =  -framework GLUT -framework OpenGL -framework Cocoa
src = main.c

all:
gcc -o $(NAME) $(COMFLAGS) main.c $(LINKFLAGS)
