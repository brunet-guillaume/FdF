# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 21:35:49 by gbrunet           #+#    #+#              #
#    Updated: 2024/03/25 11:52:44 by gbrunet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_BLACK = \033[0;30m
_RED = \033[0;31m
_GREEN = \033[0;32m
_BLUE = \033[0;34m
_YELLOW = \033[0;33m
_PURPLE = \033[0;35m
_CYAN = \033[0;36m
_WHITE = \033[0;37m

_BOLD = \e[1m
_THIN = \e[2m

_END = \033[0m

NAME = fdf

NAME_BONUS = fdf_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(X11) -Ilibft/includes

LIBFT = libft

MINILIBX = minilibx-linux

X11 = /usr/X11/include

X11LIB = $(X11)/../lib

INCLUDES = includes

SRC_DIR = sources/

BONUS_DIR = bonus/

OBJ_DIR = objects/

OBJ_BONUS_DIR = objects/bonus/

SRC_FILES = fdf errors interactions \
		color_helper color_converter image_helper \
		math_helper math_helper_2 \
		draw_line_AA draw_map \
		rotate translate scale \
		hooks mlx \
		file parser
SRC_FILES_BONUS = fdf errors interactions ui\
		color_helper color_converter image_helper \
		math_helper math_helper_2 \
		draw_line_AA draw_map draw_parallel \
		rotate translate scale \
		hooks mlx \
		file parser

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

SRC_B = $(addprefix $(BONUS_DIR), $(addsuffix _bonus.c, $(SRC_FILES_BONUS))) 

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_B = $(addprefix $(OBJ_BONUS_DIR), $(addsuffix _bonus.o, $(SRC_FILES_BONUS)))

COMPTEUR = 0

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(eval COMPTEUR=$(shell echo $$(($(COMPTEUR)+1))))
	@printf "\e[?25l"
	@mkdir -p $(OBJ_DIR)
	@if test $(COMPTEUR) -eq 1;then \
		printf "$(_YELLOW)Compiling $(NAME) binary files...$(_END)\n\n";fi
	@printf "\033[A\33[2K\r$(_CYAN)Binary $(COMPTEUR): $@$(_END)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(OBJ_BONUS_DIR)%.o: $(BONUS_DIR)%.c
	$(eval COMPTEUR=$(shell echo $$(($(COMPTEUR)+1))))
	@printf "\e[?25l"
	@mkdir -p $(OBJ_BONUS_DIR)
	@if test $(COMPTEUR) -eq 1;then \
		printf "$(_YELLOW)Compiling $(NAME_BONUS) binary files...$(_END)\n\n";fi
	@printf "\033[A\33[2K\r$(_CYAN)Binary $(COMPTEUR): $@$(_END)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

MLX = -lmlx -L $(MINILIBX) -lXext -lX11 -lm

.PHONY : all clean fclean re bonus norme

all : $(NAME)

bonus : $(NAME_BONUS)

lib :
	@make -C $(LIBFT) --no-print-directory
	@echo "$(_YELLOW)Compiling MinilibX...$(_END)"
	@make -C $(MINILIBX) --no-print-directory --silent


$(NAME) : $(OBJ)
	@make lib
	@make info --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L $(X11LIB) $(MLX) -lft -L ./libft
	@echo "$(_GREEN)$(NAME) created$(_END)"
	@printf "\e[?25h"

$(NAME_BONUS) : $(OBJ_B)
	@make lib
	@make info --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_BONUS) $(MLX) -L $(X11LIB) -lft -L ./libft
	@echo "$(_GREEN)$(NAME_BONUS) created$(_END)"
	@printf "\e[?25h"

clean :
	@make clean -C $(LIBFT) --no-print-directory
	@echo "$(_YELLOW)Cleaning MinilibX...$(_END)"
	@make clean -C $(MINILIBX) --no-print-directory --silent
	@echo "$(_YELLOW)$(NAME): Clean...$(_END)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(_GREEN)$(NAME): Binaries deleted...$(_END)"

fclean :
	@make fclean -C $(LIBFT) --no-print-directory
	@echo "$(_YELLOW)Cleaning MinilibX...$(_END)"
	@make clean -C $(MINILIBX) --no-print-directory --silent
	@echo "$(_YELLOW)$(NAME): Full clean...$(_END)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(_GREEN)$(NAME): Binaries deleted...$(_END)"
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(_GREEN)$(NAME) deleted...$(_END)"

re : 
	@make fclean --no-print-directory
	@make all --no-print-directory

norme :
	@norminette $(SRC) $(LIBFT) $(SRC_B) | grep -v Norme -B1 || true
	@norminette $(INCLUDES) -R CheckDefine | grep -v Norme -B1 || true

info :
	@printf "\t$(_PURPLE)╭──────────────────────────────────────╮"
	@printf "\n\t│$(_END)  👾  $(_CYAN)$(_THIN)Coded by $(_END)$(_CYAN)"
	@printf "$(_BOLD)guillaume brunet$(_END)$(_PURPLE)       │\n"
	@printf "\t│$(_END)  💬  $(_RED)$(_BOLD)Do not copy$(_END)$(_RED)$(_THIN), "
	@printf "$(_END)$(_RED)this is useless...$(_END) $(_PURPLE)│\n"
	@printf "\t╰──────────────────────────────────────╯\n$(_END)"
