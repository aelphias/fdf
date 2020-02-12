# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarole <acarole@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 20:22:27 by eleanna           #+#    #+#              #
#    Updated: 2020/02/12 23:27:29 by acarole          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORKS= -lmlx -framework OpenGL -framework AppKit
FLAGS= -Wextra -Wall -Werror -I.
NAME=fdf
SRC=src/main.c src/check_input.c src/draw.c src/read_file.c src/bonuses.c src/functions.c src/print_menu.c
INCLUDES=libft/libft.a

# COLORS

BLUE = \033[3;34m
GREEN = \033[5;32m
RESET = \033[0m

all:
	@make -C libft/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAMEWORKS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
clean:
	@make -C libft/ clean
	@echo "$(NAME): $(BLUE)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(BLUE)object files were deleted$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
