NAME = scope
COMFLAGS = -Wall -Werror -Wextra -g3 -w -I ./libft -L./libft -lft
CFLAGS = -I./Glfw/include/GLFW -L./Glfw/lib
LDFLAGS = -I./Glew/include/GL -L./Glew/lib
LINKFLAGS = -lGLEW -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
src = test.c

all:
	gcc -o $(NAME) $(COMFLAGS) $(CFLAGS) $(LDFLAGS) $(src) $(LINKFLAGS)
