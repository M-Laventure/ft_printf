# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 14:33:11 by mybenzar          #+#    #+#              #
#    Updated: 2019/04/12 12:49:48 by mybenzar         ###   ########.fr        #
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

TSTDIR = ./tests/
TEST = test.out
MAIN = main.c

LFTDIR = ./libft/
LFT = libft.a
HEADERS = ft_printf.h

SOURCES =	converter.c printf_utils.c args_conv.c ft_printf.c debug_functions.c\
			print_float.c calculator.c

OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(LFTDIR)$(LFT) $(OBJ)
	@echo "\033[92m Copy libftprintf.a in libft \033[0m"
	cp $< ./$@
	@echo "\033[92m Compilation\033[0m"
	$(CC) -c $(CFLAGS) $(SOURCES) -I $(HEADERS)
	ar -r $@ $(OBJECTS)
	ranlib $@
	@echo "\033[92m Name Created V\033[0m"

$(LFTDIR)$(LFT):
	@echo "\033[92m Libft Make V\033[0m"
	cd $(LFTDIR) && (MAKE)

clean:
	@echo "\033[92m Clean Objects & Libft Objects V\033[0m"
	cd $(LFTDIR) && (MAKE)
	rm -fv $(OBJECTS)
	@rm -f $(TSTDIR)$(MAIN:.c=.o)
	$(MAKE) -C $(LFTDIR) clean

fclean: clean
	@echo "\033[92m Clean Objects & Names V\033[0m"
	rm -fv $(NAME)
	#rm -f libftprintf.a
	cd $(LFTDIR) && rm -f libft.a

re:	fclean all

test: $(NAME)
	@printf "\tRebuilding test.out for rule 'test'\n"
	$(CC) $(CFLAGS) -c $(TSTDIR)$(MAIN) -o $(TSTDIR)$(MAIN:.c=.o)
	$(CC) $(OBJECTS) $(TSTDIR)$(MAIN:.c=.o) -lftprintf -L./ -o $(TEST)
	@printf "\tDone ! Usage: ""./test.out {value|NULL}""\n"

.PHONY: clean fclean

