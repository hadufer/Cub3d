/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_extension.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/17 08:21:32 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 08:21:32 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

void	check_map_extension(char *path)
{
	int	size;

	size = ft_strlen(path);
	if (path[size - 4] != '.' || path[size - 3] != 'c'
		|| path[size - 2] != 'u' || path[size - 1] != 'b')
	{
		printf("Error\nInvalid extension\n");
		exit(1);
	}
}
