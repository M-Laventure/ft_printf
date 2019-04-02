# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 14:33:11 by mybenzar          #+#    #+#              #
#    Updated: 2019/04/02 16:50:25 by mybenzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
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

SOURCES = printf/converter.c printf/printf_utils.c printf/main.c printf/args_conv.c printf/ft_printf.c printf/debug_functions.c 
OBJECTS = $(SOURCES:.c=.o)
SRCPATH = printf/
LIBPATH = libft/

all: $(NAME)

#$(NAME): lib $(OBJECTS)
#	    libtool -static -o $@ $^
#		ar -t libftprintf.a

$(NAME): lib $(OBJECTS)
	$(CC) $(CFLAGS) -L$(LIBPATH) -lft -o $(NAME) $(OBJECTS)

lib:
	cd $(LIBPATH) && (MAKE)

clean:
	rm -rf $(OBJECTS)
	$(MAKE) -C $(LIBPATH) clean

fclean: clean
		rm -rf $(NAME)
		#rm -f libftprintf.a
		cd $(LIBPATH) && rm -f libft.a

re:	fclean all

.PHONY: clean fclean

