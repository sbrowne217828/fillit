# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtavares <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/01 12:06:04 by gtavares          #+#    #+#              #
#    Updated: 2017/11/19 02:08:32 by labrown          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
SRC		= check_errors.c \
		  main.c \
		  tet.c \
		  map.c \
		  get_tet_coord.c \
		  store_tets.c \
		  recursive.c \
		  kane_alloc_wrap.c

FLAGS	= -Wall -Werror -Wextra -g
OBJ		= $(SRC:.c=.o)
MAKE	= -C libft/

.PHONY	= all clean fclean re

all: $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRC)
	@make $(MAKE) all
	@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@make $(MAKE) clean
	@/bin/rm -f $(OBJ) 
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@make $(MAKE) fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
