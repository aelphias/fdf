# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/10 13:58:56 by aelphias          #+#    #+#              #
#    Updated: 2020/02/04 17:04:21 by aelphias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re lib

NAME =			fdf

SRC =			main.c

OBJ =			$(SRC:.c=.o)

FT_LIB =		libft/libft.a minilibx_macos/libmlx.a

FT_PRINT =		ft_printf/libftprintf.a

CFLAGS =		-Wall -Wextra -Werror -g

all:			$(NAME)

%.o:			%.c
				gcc -g -I ./libft -I ./ft_printf -o $@ -c $<

$(NAME):		$(FT_LIB) $(FT_PRINT) $(OBJ) libft/libft.a ft_printf/libftprintf.a
				gcc  -o $(NAME) $(OBJ) -L ./libft -lft -L ./ft_printf -lftprintf

FORCE:			;

$(FT_LIB):		FORCE
				make -C ./libft

$(FT_PRINT):	FORCE
				make -C ./ft_printf

clean:		
				/bin/rm -f $(OBJ)
				make clean -C ./libft
				make clean -C ./ft_printf

fclean: 		clean
				make fclean -C ./libft
				make fclean -C ./ft_printf
				/bin/rm -f $(NAME)
				
re:				fclean all
