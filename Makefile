# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 10:41:12 by hadufer           #+#    #+#              #
#    Updated: 2022/03/12 10:49:01 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
RM = rm -f
CFLAGS = -g

SRCS =	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./Libftprintf/Libft -I./Libftprintf -Imlx -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS) ./Libftprintf/libftprintf.a
	$(CC) $(OBJS) -lmlx ./libftprintf/libftprintf.a -framework OpenGL -framework AppKit -o $(NAME)

./Libftprintf/libftprintf.a:
	$(MAKE) -C ./Libftprintf

clean:
	$(MAKE) -C ./Libftprintf $@
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C ./Libftprintf $@
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean flcean re 