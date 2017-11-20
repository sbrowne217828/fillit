# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtavares <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 15:29:40 by gtavares          #+#    #+#              #
#    Updated: 2017/09/28 18:45:33 by gtavares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =    libft.a

SRC            =     ./
HEADER        =    ./includes/

FILENAMES    =    ft_memset.c ft_memcpy.c ft_bzero.c ft_memccpy.c ft_strdup.c  \
                ft_toupper.c ft_tolower.c ft_memchr.c ft_memmove.c ft_strcmp.c \
                ft_isalnum.c ft_isalpha.c ft_isascii.c ft_memcmp.c ft_strncmp.c \
                ft_isdigit.c ft_isprint.c ft_strlen.c ft_strcpy.c ft_strncpy.c \
				ft_atoi.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
				ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
				ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
				ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \

OBJECTS        = ${FILENAMES:c=o}

OPTION        =    -c -I $(HEADER)

SOURCES        =    $(addprefix $(SRC), $(FILENAMES))

all : $(NAME)

$(NAME):
	@ gcc -Wall -Wextra -Werror $(OPTION) $(SOURCES)
	@ ar rc $(NAME) $(OBJECTS)

clean:
	@ rm -f $(OBJECTS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all
