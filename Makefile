# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:22:27 by eleanna           #+#    #+#              #
#    Updated: 2020/02/17 16:13:41 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FRAMEWORKS	=	-lmlx -framework OpenGL -framework AppKit

FLAGS		=	-Wextra -Wall

NAME		=	fdf

SRC			=	src/main.c src/check_input.c src/draw.c src/read_file.c \
				src/bonuses.c	src/functions.c src/print_menu.c \
				src/keys_n_mouse.c src/rotation.c
			
FT_LIB		=	./libft/libft.a

LIBFT_PATH = ./libft

OBJ			=	$(SRC:.c=.o)

INC			=	./includes/fdf.h

INCLUDES_PATH = ./includes

CC			=	gcc

# COLORS

RED = \033[0;91m
GREEN = \033[0;92m
RESET = \033[0m

all: $(NAME)
	
$(NAME): $(FT_LIB) $(OBJ)
	$(CC) $(FRAMEWORKS) $(FLAGS) -I ./includes -I $(LIBFT_PATH) $(SRC) -L ./libft -lft -o $(NAME)
	@echo "\n$(GREEN)object files were created$(RESET)"
	@echo "$(GREEN)$(NAME) executable file was created$(RESET)"


%.o: %.c $(INC)
	$(CC) $(FLAGS) -o $@ -c $< -I ./includes -I ./libft
	
$(FT_LIB): force
	make -C ./libft

clean:
	@/bin/rm -rf src/main.o
	@make -C libft/ clean
	@/bin/rm -f src/$(OBJ)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY)executable file was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re force
