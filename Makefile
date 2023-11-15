# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 21:35:49 by gbrunet           #+#    #+#              #
#    Updated: 2023/11/15 21:58:01 by gbrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

INCLUDES = includes

SRC_DIR = sources/

OBJ_DIR = objects/

SRC_FILES = fdf \
		color_helper image_helper math_helper \
		draw_line draw_line_AA \
		rotate translate \
		hooks

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

MLX = ./minilibx-linux/libmlx.a -lXext -lX11 -lm

.PHONY : all clean fclean re run norme

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -L./$(LIBFT)/ -lft $(OBJ) -o $(NAME) $(MLX)

clean :
	make clean -C $(LIBFT)
	$(RM) -rf $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

run : all
	./$(NAME)

norme :
	@norminette $(SRC) $(LIBFT) | grep -v Norme -B1 || true
	@norminette $(INCLUDES) -R CheckDefine | grep -v Norme -B1 || true

