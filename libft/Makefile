# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 10:00:18 by gbrunet           #+#    #+#              #
#    Updated: 2024/03/20 10:13:45 by gbrunet          ###   ########.fr        #
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

NAME = libft.a

CC = cc

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

SRC_DIR = sources/

OBJ_DIR = objects/

LIBC = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit \
	   ft_isprint ft_itoa ft_memchr ft_isspace ft_memcmp ft_memcpy ft_memmove \
	   ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
	   ft_strchr ft_split ft_space_split ft_strdup ft_striteri ft_strjoin \
	   ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
	   ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper
LIBC_FILES = $(addprefix libc/, $(LIBC))

OTHER = ft_free ft_rgba mathf_func mathi_func
OTHER_FILES = $(addprefix other/, $(OTHER))

BTREE = ft_bt_add_left ft_bt_add_right ft_bt_clear ft_bt_del ft_bt_new \
		ft_bt_print
BTREE_FILES = $(addprefix btree/, $(BTREE))

DLIST = ft_dl_add_back ft_dl_add_front ft_dl_clear ft_dl_del ft_dl_last \
		ft_dl_new ft_dl_remove_from ft_dl_size ft_dl_sort ft_dl_swap
DLIST_FILES = $(addprefix dlist/, $(DLIST))

GNL = get_next_line get_next_line_utils
GNL_FILES = $(addprefix gnl/, $(GNL))

LIST = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
	   ft_lstlast ft_lstmap ft_lstnew ft_lstsize
LIST_FILES = $(addprefix list/, $(LIST))

PRINTF = ft_printf helper options percent_parcer print_c print_d \
		 print_d_helper print_p print_s print_u print_u_helper print_x \
		 print_x_helper
PRINTF_FILES = $(addprefix printf/, $(PRINTF))

SRC = $(LIBC_FILES) $(OTHER_FILES) $(BTREE_FILES) $(DLIST_FILES) $(GNL_FILES) \
	  $(LIST_FILES) $(PRINTF_FILES)

SRC_FILES = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJ_FILES = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

COMPTEUR = 0

.PHONY : all clean fclean re bonus

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(eval COMPTEUR=$(shell echo $$(($(COMPTEUR)+1))))
	@mkdir -p $(@D)
	@printf "\e[?25l"
	@if test $(COMPTEUR) -eq 1;then \
		printf "$(_YELLOW)Compiling $(NAME) binary files...$(_END)\n\n";fi
	@printf "\033[A\33[2K\r$(_CYAN)Binary $(COMPTEUR): $@$(_END)\n"
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJ_FILES)
	@make info --no-print-directory
	@ar rc $(NAME) $(OBJ_FILES)
	@echo "$(_GREEN)Libft created.$(_END)"
	@printf "\e[?25h"

all : $(NAME)

clean :
	@echo "$(_YELLOW)$(NAME): Clean...$(_END)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(_GREEN)$(NAME): Binaries deleted.$(_END)"

fclean :
	@echo "$(_YELLOW)$(NAME): Full clean...$(_END)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(_GREEN)$(NAME): Binaries deleted.$(_END)"
	@$(RM) $(NAME)
	@echo "$(_GREEN)$(NAME) deleted.$(_END)"

re : 
	@make fclean --no-print-directory
	@make all --no-print-directory
	@printf "\e[?25h"

info :
	@printf "\t$(_PURPLE)╭──────────────────────────────────────╮"
	@printf "\n\t│$(_END)  👾  $(_CYAN)$(_THIN)Coded by $(_END)$(_CYAN)"
	@printf "$(_BOLD)guillaume brunet$(_END)$(_PURPLE)       │\n"
	@printf "\t│$(_END)  💬  $(_RED)$(_BOLD)Do not copy$(_END)$(_RED)$(_THIN), "
	@printf "$(_END)$(_RED)this is useless...$(_END) $(_PURPLE)│\n"
	@printf "\t╰──────────────────────────────────────╯\n$(_END)"
