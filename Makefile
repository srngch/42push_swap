# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 13:55:37 by sarchoi           #+#    #+#              #
#    Updated: 2022/02/09 02:49:10 by sarchoi          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# TODO: remove wildcard
SRCS = $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L $(LIBFT) -lft
INC_FLAGS = -I includes -I $(LIBFT)

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make all --silent --directory=$(LIBFT)
	@make all --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> make Libft$(reset))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) $(OBJS) $(LIBFT_FLAGS)
	$(info $(green)<MAKE> NAME$(reset))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
	$(info $(green)<MAKE> $(<) -> $(@)$(reset))

clean:
	@make clean --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> Libft - clean$(reset))
	@rm -f $(OBJS)
	$(info $(green)<MAKE> clean$(reset))

# TODO: check if gnl is clean
fclean: clean
	@make fclean --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> Libft - fclean$(reset))
	@rm -f $(NAME)
	$(info $(green)<MAKE> fclean$(reset))

re: fclean all
	$(info $(red)<MAKE> re$(reset))

.PHONY: all clean fclean re $(LIBFT)
