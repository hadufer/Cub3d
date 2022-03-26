/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   characters.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/17 08:17:50 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 08:17:50 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

int	condition2(char c)
{
	if (c != '1' && c != '0' && c != '\n' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W' && c != ' ' && c != '\t')
		return (1);
	return (0);
}

void	check_characters(char *path, int i)
{
	char	*file;

	file = get_file(path);
	while (file[i])
	{
		if (condition2(file[i]) == 1)
		{
			printf("Error\nInvalid charater\n");
			exit(1);
		}
		i++;
	}
	free(file);
}
