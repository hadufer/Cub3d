/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:24:53 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 08:42:07 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_error_map(void)
{
	printf("Error\nMap description not found\n");
	exit(1);
}

void	assign(int *last, char *c, int i, char direction)
{
	*last = i;
	*c = direction;
}

int	get_last(t_texture_coords texture_coords)
{
	int		last;
	char	c;

	last = 0;
	if (texture_coords.no.i > last)
		assign(&last, &c, texture_coords.no.i, 'N');
	if (texture_coords.so.i > last)
		assign(&last, &c, texture_coords.so.i, 'S');
	if (texture_coords.ea.i > last)
		assign(&last, &c, texture_coords.ea.i, 'E');
	if (texture_coords.we.i > last)
		assign(&last, &c, texture_coords.we.i, 'W');
	if (texture_coords.f.i > last)
		assign(&last, &c, texture_coords.f.i, 'F');
	if (texture_coords.c.i > last)
		assign(&last, &c, texture_coords.c.i, 'C');
	return (last);
}

int	get_i(t_texture_coords texture_coords, char *path)
{
	int		j;
	int		temp;
	char	*file;
	int		last;

	j = 0;
	temp = 0;
	file = get_file(path);
	last = get_last(texture_coords);
	while (temp++ != last)
	{
		while (file[j] != '\n')
			j++;
		if (file[j] == '\n')
			j++;
	}
	while (file[j] != '\n')
	{
		if (file[j++] == '\0' || file[j + 1] == '\0')
			print_error_map();
	}
	if (file[j] == '\n')
		j++;
	free(file);
	return (j);
}

int	check_texture(char *path, t_texture_coords *texture_coords)
{
	char	**file;

	file = parse_file(path);
	check_north(file, texture_coords);
	check_south(file, texture_coords);
	check_west(file, texture_coords);
	check_east(file, texture_coords);
	check_floor(file, texture_coords);
	check_ceiling(file, texture_coords);
	free_map(file);
	return (get_i(*texture_coords, path));
}
