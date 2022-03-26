/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_and_last_character_in_map.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:49:49 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 07:52:47 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_first_character_in_map(char *file, int i)
{
	int	temp;
	int	nl;

	nl = i;
	while (file[i] != '1' && file[i] != '0' && file[i] != 'N'
		&& file[i] != 'S' && file[i] != 'E' && file[i] != 'W')
	{
		if (file[i] == '\n')
			nl = i + 1;
		i++;
	}
	temp = nl;
	while (file[temp])
		if (file[temp++] == '\n')
			return (nl);
	printf("Error\nInvalid map description\n");
	exit(1);
}

//check that file contains only '\n' or ' ' for the current file
//return 1 if true, 0 if false
int	nothing_in_line(char *file, int i)
{
	int	temp;

	temp = 0;
	while (file[i] != '\n')
	{
		if (file[i] != ' ' && temp != 0)
			return (0);
		i++;
		temp++;
	}
	return (1);
}

void	skip_line(char *file, int *i)
{
	while (file[*i] != '\n')
	{
		*i += 1;
	}
	*i += 1;
}

int	get_last_character_in_map(char *file, int i)
{
	int	last_c;

	last_c = 0;
	while (file[i])
	{
		if (file[i] == '1' || file[i] == '0' || file[i] == 'N'
			|| file[i] == 'W' || file[i] == 'E' || file[i] == 'S')
			last_c = i;
		i++;
	}
	return (last_c);
}
