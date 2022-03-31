# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nferre <nferre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 10:41:12 by hadufer           #+#    #+#              #
#    Updated: 2022/03/31 15:44:32 by nferre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SRCS =	./mlx_utils.c   \
./draw_ray_util.c   \
./key_handling.c   \
./libft/ft_strnstr.c   \
./libft/ft_isdigit.c   \
./libft/ft_lstadd_back.c   \
./libft/ft_putstr_fd.c   \
./libft/ft_lstnew.c   \
./libft/ft_strlcpy.c   \
./libft/ft_strlen.c   \
./libft/ft_lstlast.c   \
./libft/ft_memcmp.c   \
./libft/ft_putnbr_fd.c   \
./libft/ft_lstclear.c   \
./libft/ft_lstiter.c   \
./libft/ft_strchr.c   \
./libft/ft_striteri.c   \
./libft/ft_bzero.c   \
./libft/ft_strjoin.c   \
./libft/ft_isascii.c   \
./libft/ft_memcpy.c   \
./libft/ft_isprint.c   \
./libft/ft_putendl_fd.c   \
./libft/ft_lstmap.c   \
./libft/ft_lstsize.c   \
./libft/ft_toupper.c   \
./libft/ft_split.c   \
./libft/ft_lstadd_front.c   \
./libft/ft_strrchr.c   \
./libft/ft_isalpha.c   \
./libft/ft_memchr.c   \
./libft/ft_putchar_fd.c   \
./libft/ft_memset.c   \
./libft/ft_substr.c   \
./libft/ft_strncmp.c   \
./libft/ft_strmapi.c   \
./libft/ft_strtrim.c   \
./libft/ft_strndup.c   \
./libft/ft_memmove.c   \
./libft/ft_strlcat.c   \
./libft/ft_calloc.c   \
./libft/ft_strdup.c   \
./libft/ft_atoi.c   \
./libft/ft_isalnum.c   \
./libft/ft_lstdelone.c   \
./libft/ft_itoa.c   \
./libft/ft_tolower.c   \
./graphic.c   \
./draw_ray.c   \
./main.c   \
./util_main.c   \
./graphic_utils.c   \
./srcs/utils/init_coords.c   \
./srcs/utils/free.c   \
./srcs/utils/ft_isspace.c   \
./srcs/parsing/int_map.c   \
./srcs/parsing/parse_map.c   \
./srcs/parsing/parse_utils.c   \
./srcs/parsing/get_first_and_last_character_in_map.c   \
./srcs/parsing/parse.c   \
./srcs/parsing/parse_file.c   \
./srcs/parsing/check/map_empty.c   \
./srcs/parsing/check/order_texture_utils.c   \
./srcs/parsing/check/args.c   \
./srcs/parsing/check/checker.c   \
./srcs/parsing/check/floor_ceiling.c   \
./srcs/parsing/check/texture.c   \
./srcs/parsing/check/map_existence.c   \
./srcs/parsing/check/texture_existance.c   \
./srcs/parsing/check/characters.c   \
./srcs/parsing/check/format_colors.c   \
./srcs/parsing/check/all_directions.c   \
./srcs/parsing/check/map_extension.c   \
./srcs/parsing/check/texture_number.c   \
./srcs/parsing/check/map.c   \
./srcs/parsing/check/walls.c   \
./srcs/parsing/check/number_map.c   \
./srcs/parsing/check/colors.c   \

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
