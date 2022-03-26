/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   walls.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/17 08:27:37 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 08:28:06 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

int	check_for_walls(char **map, int i, int j)
{
	int	max_length;

	max_length = 0;
	while (map[i][max_length])
		max_length++;
	if (map[i][j + 1] == '\n' || map[i][j + 1] == ' ')
		return (1);
	if (j == 0 || map[i][j - 1] == ' ')
		return (2);
	if (i == 0 || map[i - 1][j] == ' ')
		return (3);
	if (map[i + 1] == NULL || map[i + 1][j] == ' ')
		return (4);
	if (map[i + 1][j + 1] == ' ')
		return (5);
	if (map[i + 1][j - 1] == ' ')
		return (6);
	if (j >= max_length || map[i - 1][j + 1] == ' '
		|| map[i - 1][j + 1] == '\n')
		return (7);
	if (map[i - 1][j - 1] == ' ')
		return (8);
	return (0);
}

void	print_error_walls(void)
{
	printf("Error\nInvalid Walls\n");
	exit(1);
}

void	check_walls(char *path, int first_c, t_data *data)
{
	int		i;
	int		j;
	char	*file;

	i = -1;
	file = get_file(path);
	data->map = parse_map(file, first_c);
	data->file = parse_file(path);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W')
			{
				if (check_for_walls(data->map, i, j) >= 1)
					print_error_walls();
			}
		}
	}
	free(file);
}
