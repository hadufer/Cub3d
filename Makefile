# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 10:41:12 by hadufer           #+#    #+#              #
#    Updated: 2022/03/29 16:18:54 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	$(wildcard *.c) \
		$(wildcard srcs/*.c) \
		$(wildcard srcs/parsing/*.c) \
		$(wildcard srcs/parsing/check/*.c) \
		$(wildcard srcs/utils/*.c)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./includes -I./libft -I./libft -Imlx -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS) ./libft/libft.a
	$(CC) $(OBJS) -lmlx ./libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

./libft/libft.a:
	$(MAKE) -C ./libft bonus
	cp libft/libft.a $(NAME)

clean:
	$(MAKE) -C ./libft $@
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./libft $@
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flcean re