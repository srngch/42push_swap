# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 13:55:37 by sarchoi           #+#    #+#              #
#    Updated: 2022/01/26 19:09:54 by sarchoi          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# TODO: remove wildcard
SRCS = $(wildcard src/*.c) $(wildcard src/*/*.c)
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L libs/$(LIBFT) -lft

GNL = gnl
SRCS_GNL = libs/$(GNL)/get_next_line_utils.c \
		   libs/$(GNL)/get_next_line.c
OBJS_GNL = $(SRCS_GNL:.c=.o)

INC_FLAGS = -I includes -I libs/$(LIBFT) -I libs/$(GNL)

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make all --silent --directory=libs/$(LIBFT)
	@make bonus --silent --directory=libs/$(LIBFT)
	$(info $(green)<MAKE> Libft - make bonus$(reset))

# $(OBJS_GNL)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SERVER) $(OBJS) $(LIBFT_FLAGS)
	$(info $(green)<MAKE> NAME$(reset))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)
	$(info $(green)<MAKE> $(<) -> $(@)$(reset))

clean:
	@make clean --silent --directory=libs/$(LIBFT)
	$(info $(green)<MAKE> Libft - clean$(reset))
	@rm -f $(OBJS) $(OBJS_GNL)
	$(info $(green)<MAKE> clean$(reset))

# TODO: check if gnl is clean
fclean: clean
	@make fclean --silent --directory=libs/$(LIBFT)
	$(info $(green)<MAKE> Libft - fclean$(reset))
	@rm -f $(NAME)
	$(info $(green)<MAKE> fclean$(reset))

re: fclean all
	$(info $(red)<MAKE> re$(reset))

.PHONY: all clean fclean re $(LIBFT)
