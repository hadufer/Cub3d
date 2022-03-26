/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:20:35 by nferre            #+#    #+#             */
/*   Updated: 2022/03/22 07:30:39 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_if_map_empty(char *path)
{
	char	*file;

	file = get_file(path);
	if (file[0] == '\0')
	{
		free(file);
		printf("Error\nFile empty\n");
		exit(1);
	}
	free(file);
}
