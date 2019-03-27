# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 14:33:11 by mybenzar          #+#    #+#              #
#    Updated: 2019/03/27 17:55:10 by malavent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc 

ifdef FLAGS
	ifeq ($(FLAGS), no)
	CFLAGS=
endif

ifeq ($(FLAGS), debug)
	CFLAGS= -Wall -Wextra -Werror -ansi -pedantic -g
endif

else
	CFLAGS = -Wall -Wextra -Werror
endif

SOURCES = srcs/converter.c srcs/printf_utils.c srcs/main.c srcs/args_conv.c srcs/ft_printf.c 
OBJECTS = $(SOURCES:.c=.o)
LIBPATH = libft/
INC = -I includes/

all : $(NAME)

$(NAME): lib $(OBJECTS)
	$(CC) $(CFLAGS) -L$(LIBPATH) -lft -o $(NAME) $(OBJECTS)

lib:
	cd $(LIBPATH) && (MAKE)

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C $(LIBPATH) clean

fclean: clean
		rm -f $(NAME)
			cd $(LIBPATH) && rm -f libft.a

re:	fclean all

.PHONY: clean fclean

