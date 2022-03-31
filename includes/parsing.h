/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:54:53 by nferre            #+#    #+#             */
/*   Updated: 2022/03/31 15:24:44 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "cube.h"
# include "cub.h"

typedef struct s_coords
{
	int	i;
	int	j;

}	t_coords;

typedef struct s_texture_coords
{
	t_coords	no;
	t_coords	so;
	t_coords	ea;
	t_coords	we;
	t_coords	f;
	t_coords	c;

}	t_texture_coords;

typedef struct s_color	t_color;

typedef struct s_data	t_data;

//parsing

t_data				*parse(int argc, char **argv);
char				**parse_map(char *file, int i);
char				**parse_file(char *path);
int					get_first_character_in_map(char *file, int i);
int					get_last_character_in_map(char *file, int i);

//checker

t_texture_coords	checker(char *path, t_data *data, int argc);
void				check_args(int argc);
int					check_texture(char *path, t_texture_coords *texture_coords);
void				check_map_extension(char *path);
void				check_map_existence(char *path);
void				check_characters(char *path, int i);
void				check_number_maps(char *path, int i);
void				check_walls(char *path, int i, t_data *data);
void				check_north(char **file, t_texture_coords *texture_coords);
void				check_south(char **file, t_texture_coords *texture_coords);
void				check_west(char **file, t_texture_coords *texture_coords);
void				check_east(char **file, t_texture_coords *texture_coords);
void				check_floor(char **file, t_texture_coords *texture_coords);
void				check_ceiling(char **file,
						t_texture_coords *texture_coords);
void				check_texture_existence(t_data *data);
void				check_colors(char *path, t_texture_coords texture_coords);
void				check_if_map_empty(char *path);
void				check_number_texture(t_data *data);
void				check_map(t_data *data);
void				get_textures(t_data *data);
void				get_int_map(t_data *data);
void				check_texture_map(t_data *data, char x, char y);
void				check_number_texture(t_data *data);
void				check_format_colors(t_data *data, t_texture_coords t_c);

//utils

void				print_error(int i, char **file, int j);
void				print_tab(char **map);
int					get_size(char *path);
char				*get_file(char *path);
int					condition(char *file, int i);
void				init_coords(t_texture_coords *texture_coords);
void				print_color(t_color color);
char				*get_path(char **file, t_coords coords, int i);

#endif