/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   number_map.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/17 08:23:06 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 08:23:06 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

int	check_if_line_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
	}
	return (1);
}

int	check_if_other_lines_empty(char **map, int i)
{
	while (map[++i])
	{
		if (check_if_line_empty(map[i]) == 0)
			return (0);
	}
	return (1);
}

void	check_number_maps(char *path, int i)
{
	int		j;
	char	**map;
	char	*file;

	j = -1;
	file = get_file(path);
	map = parse_map(file, i);
	while (map[++j])
	{
		if (check_if_line_empty(map[j]) == 1)
		{
			if (check_if_other_lines_empty(map, j) == 0)
			{
				printf("Error\nInvalid number of maps\n");
				exit(1);
			}
		}
	}
	free_map(map);
	free(file);
}
