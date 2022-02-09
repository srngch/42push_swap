# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 13:55:37 by sarchoi           #+#    #+#              #
#    Updated: 2022/02/09 15:27:58 by sarchoi          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ./src/main.c ./src/parse.c ./src/check.c \
	./src/stack_count.c ./src/stack_find.c ./src/stack_rotate.c \
	./src/ps_atol.c ./src/util_stack_1.c ./src/util_stack_2.c\
	./src/sort_2_to_5.c ./src/sort_many.c \
	./src/operation/push.c ./src/operation/reverse.c \
	./src/operation/rotate.c ./src/operation/swap.c
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
	make $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) $(OBJS) $(LIBFT_FLAGS)
	$(info $(green)<MAKE> NAME$(reset))

%.o: %.c
	make $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
	$(info $(green)<MAKE> $(<) -> $(@)$(reset))

clean:
	@make clean --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> Libft - clean$(reset))
	@rm -f $(OBJS)
	$(info $(green)<MAKE> clean$(reset))

fclean: clean
	@make fclean --silent --directory=$(LIBFT)
	$(info $(green)<MAKE> Libft - fclean$(reset))
	@rm -f $(NAME)
	$(info $(green)<MAKE> fclean$(reset))

re: fclean all
	$(info $(red)<MAKE> re$(reset))

.PHONY: all clean fclean re $(LIBFT)
