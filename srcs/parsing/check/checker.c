/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   checker.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/17 08:18:20 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 08:18:22 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

t_texture_coords	checker(char *path, t_data *data, int argc)
{
	int					i;
	t_texture_coords	texture_coords;

	init_coords(&texture_coords);
	check_args(argc);
	check_map_existence(path);
	check_map_extension(path);
	check_if_map_empty(path);
	i = check_texture(path, &texture_coords);
	check_colors(path, texture_coords);
	check_characters(path, i);
	check_walls(path, i, data);
	check_map(data);
	check_number_maps(path, i);
	return (texture_coords);
}
