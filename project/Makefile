NAME		= cub3D

C_FLAG		=

DIR_SRC		= src/
DIR_OBJ		= bin/
INCLUDES	= includes
LIBMLX_PATH	= ../minilibx_mms_20200219
LIBFT		= libft.a
#VPATH		= src bin includes
HEADERS		:= cub3D.h

SRC			:= get_next_line.c get_next_line_utils.c \
			cub3D.c parse_utils.c func_window.c ft_parse.c \
			ft_parse_map.c


OBJ			:= $(SRC:c=o)

SRC			:= $(addprefix $(DIR_SRC), $(SRC))
OBJ			:= $(addprefix $(DIR_OBJ), $(OBJ))

$(DIR_OBJ)%.o:		$(DIR_SRC)%.c $(INCLUDES)/$(HEADERS)
	mkdir -p bin
	gcc $(C_FLAG) -c $< -o $@ -I$(INCLUDES)


all:		$(LIBFT) $(NAME)

$(NAME):	 $(OBJ)
	@$(MAKE) -C $(LIBMLX_PATH)
	mv $(LIBMLX_PATH)/libmlx.dylib .
	gcc $^ -L. -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	#cp libft/libft.h includes
	@$(MAKE) -C libft
	#@ make bonus -C libft
	cp libft/libft.a .

clean:
	make clean -C libft
	rm -r $(OBJ) $(LIBFT)

fclean: 	clean
	rm -f $(NAME) $(LIBFT) $(LIBMLX)

re:			clean all