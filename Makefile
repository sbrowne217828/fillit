# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labrown <labrown@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 15:17:47 by labrown           #+#    #+#              #
#    Updated: 2017/10/21 12:31:46 by labrown          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c tetriminos.c open_file.c solve.c map.c extra.c
OBJS = $(addprefix $(OBJD), $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
FTINC = -I ./libft/
FTLINK = -L ./libft/ -lft

OBJD = ./obj/
SRCD = ./src/
INCD = ./includes/

.PHONY: all clean fclean re

all: obj libft $(NAME)

obj:
	mkdir -p $(OBJD)

$(OBJD)%.o: $(SRCD)%.c
	gcc $(CFLAGS) $(FTINC) -I $(INC) -c $< -o $@

$(NAME):
	$(CC) $(OBJS) $(FTLINK) -o $(NAME)

libft: $(LIBFT)

$(LIBFT):
		make -C ./libft/

clean:
	/bin/rm -rf $(OBJD)

fclean: clean
	/bin/rm -rf $(NAME)

re:	fclean all
