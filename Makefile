# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aberneli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/16 14:59:12 by aberneli          #+#    #+#              #
#    Updated: 2022/01/04 10:44:08 by aberneli         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker

CC := gcc
FLAGS := -Wall -Wextra -Werror -I.

HEADER := push_swap.h

HEADER_BONUS := get_next_line.h

SRC := main.c ft_atoi.c push.c rotate.c rrotate.c stack.c swap.c \
	normalize_data.c super_fetchrange.c super_fetchx.c super_sortb.c \
	super_small.c data.c ft_splclean.c ft_split.c ft_strlen.c

SRC_BONUS := main_checker.c ft_atoi.c push.c rotate.c rrotate.c stack.c \
	swap.c normalize_data.c data.c ft_splclean.c ft_split.c ft_strlen.c \
	get_next_line.c get_next_line_utils.c

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
