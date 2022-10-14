# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eclark <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 10:59:18 by eclark            #+#    #+#              #
#    Updated: 2022/10/13 17:53:31 by eclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = cost.c error_man.c init.c main.c positionsss.c push.c rev_rotate.c \
		rotate_cost.c rotate.c sort.c swap.c utils.c ft_split.c init_string.c
SRCDIR = src/
SOURCES = $(addprefix $(SRCDIR), $(SRCS))

INCDIR = inc/

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FLAGS) $(SOURCES) -I$(INCDIR) -o $(NAME)

clean:

fclean : clean
	rm -rf $(NAME)

re: fclean clean all
