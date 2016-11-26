NAME		=	scop
LIBFTI		=	-I libft/include
LIBFTL		=	-L libft -lft
OGLI		=	-I./Glew/include/GL -I./Glfw/include/GLFW 
OGLL		=	-L./Glew/lib -L./Glfw/lib -lGLEW -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
INC			=	-I include $(LIBFTI) $(OGLI)
LIBS		=	-lm $(LIBFTL) $(OGLL)
CFLAGS		=	-Wall -Wextra -Werror -Wno-unused-result -Wno-unused-parameter $(INC)
LFLAGS		=	-Wno-unused-result $(INC) $(LIBS)
CC			=	gcc
LD			=	gcc

INCLUDE		=	$(shell find include -name "*.h")
SRC			=	$(shell find src -name "*.c")
OBJ			=	$(SRC:src/%.c=build/%.o)

all: lft rt

build/%.o: src/%.c $(INCLUDE)
		@echo "\033[92m    CC    $@\033[0m"
			@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@

rt: $(OBJ)
		@echo "\033[92m    LD    $(NAME)\033[0m"
			@$(LD) $^ $(LFLAGS) -o $(NAME)

lft:
		@make -s -C libft all

clean:
		@echo "\033[92m    RM    object files\033[0m"
			@rm -rf build
				@make -s -C libft clean

fclean: clean
		@echo "\033[92m    RM    $(NAME)\033[0m"
			@rm -f $(NAME)
				@rm -rf $(NAME).dSYM
					@make -s -C libft fclean

re: fclean all
