/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_existence.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/17 08:21:02 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 08:21:02 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

void	check_map_existence(char *path)
{
	char	buf[1];
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n%s\n", strerror(errno));
		exit(1);
	}
	if (read(fd, buf, 1) == -1)
	{
		printf("Error\n%s\n", strerror(errno));
		exit(1);
	}
	close(fd);
}
