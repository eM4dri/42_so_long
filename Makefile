# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/17 19:44:26 by emadriga          #+#    #+#              #
#    Updated: 2021/10/03 19:58:28 by emadriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program's name
NAME	= so_long

# compiling flags
FLAGS	= -Wall -Wextra -Werror -fsanitize=address

# Header files
INCLUDES_FILES =	constants.h	\
					errors.h	\
					images.h	\
					options.h	\
					so_long.h

# Source and object files
SRC_FILES	= 	sl_hooks.c				\
				sl_main.c				\
				sl_map_drawer.c			\
				sl_map_drawer2.c		\
				sl_map_move.c			\
				sl_map_move_enemies.c	\
				sl_map_parser.c			\
				sl_utils.c				\
				sl_utils2.c
OBJ_FILES	= $(SRC_FILES:.c=.o) 

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./minilibx/

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
INCLUDES = $(addprefix $(INC_DIR), $(INCLUDES_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX  = $(addprefix $(MINLBX_DIR), libmlx.a)

# Libft and Minilibx linkers
LNK  = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
	   -lmlx -framework OpenGL -framework AppKit

# all rule
all: obj $(LIBFT) $(MINLBX) $(NAME)

obj: 
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INCLUDES)
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
	@echo "Compiling... Wait a sec."
	@gcc $(OBJ) $(FLAGS) $(LNK) -lm -o $(NAME)
	@echo "$(NAME) generated!".

mynorm:
	norminette $(SRC_DIR) $(INC_DIR) $(LIBFT_DIR)

bonus:	all

# clean rule			
clean:
			@rm -Rf $(OBJ_DIR) 
			@make -C $(LIBFT_DIR) clean
			@make -C $(MINLBX_DIR) clean
			@echo "[INFO] Objects removed!"
			
# fclean rule
fclean:		clean
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "$(NAME) removed!"
			
# re rule
re:			fclean all bonus

# phony
.PHONY:		all bonus clean fclean re mynorm