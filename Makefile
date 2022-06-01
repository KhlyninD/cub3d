NAME 		= cub3d

SRC			=$(shell find srcs/ -name "*.c")

PATH_LIB 	= srcs/libft/

NAME_LIB	= libft.a

LIB			= srcs/libft/libft.a

OBJ			= $(patsubst %.c,%.o,${SRC})

D_FILES		= $(patsubst %.c,%.d,${SRC})

CFLAGS 		= -Wall -Wextra -Werror -O2 -MMD

INCLUDES	= -I includes/ -I srcs/libft/ -I mlx/

MLX_FLAGS 	= -lmlx -framework OpenGL -framework Appkit

all:		$(NAME)

$(NAME):	$(OBJ)
			echo "\n"
			make -sC mlx 2>/dev/null
			make -sC $(PATH_LIB)
			$(CC) $(FLAGS) $(MLX_FLAGS) ${INCLUDES} $(OBJ) $(LIB) -I. -o $(NAME)
			echo Done

%.o: 		%.c Makefile
			@${CC} ${CFLAGS} -c $< -o $@ ${INCLUDES}

clean:
			@make clean -C $(PATH_LIB)
			@make clean -C mlx
			@rm -f $(OBJ) $(D_FILES)

fclean: 	clean
			@make fclean -C $(PATH_LIB)
			@rm -f $(NAME) libmlx.dylib

re:			fclean all

include		$(wildcard ${D_FILES})

.SILENT: $(NAME) all

.PHONY: all clean fclean re
