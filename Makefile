NAME = scope
OS := $(shell uname)
ifeq ($(OS), Darwin)
	LINKFLAGS = -lGLEW -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
else
	LINKFLAGS = -lGLEW -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi
endif
COMFLAGS = -Wall -Werror -Wextra -g3 -I ./libft -L./libft -lft
CFLAGS = -I./Glfw/include/GLFW -L./Glfw/lib
LDFLAGS = -I./Glew/include/GL -L./Glew/lib
src = main.c load_shader.c memory.c matrix1.c matrix2.c obj_info.c open_gl.c read_material.c readobj.c \
	  rotation.c translation.c keys.c vector.c

all:
	gcc -o $(NAME) $(COMFLAGS) $(CFLAGS) $(LDFLAGS) $(src) $(LINKFLAGS)
