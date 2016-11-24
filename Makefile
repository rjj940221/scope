NAME = scope
OS = $(shell uname)
ifeq $(OS) Darwin
    # Run MacOS commands
    LINKFLAGS = -lGLEW -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else
    # check for Linux and run other commands
    LINKFLAGS = -lGLEW -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
endif
COMFLAGS = -Wall -Werror -Wextra -g3 -w -I ./libft -L./libft -lft
CFLAGS = -I./Glfw/include/GLFW -L./Glfw/lib
LDFLAGS = -I./Glew/include/GL -L./Glew/lib



src = test2.c load_shader.c memory.c matrix1.c matrix2.c

all:
	gcc -o $(NAME) $(COMFLAGS) $(CFLAGS) $(LDFLAGS) $(src) $(LINKFLAGS)
