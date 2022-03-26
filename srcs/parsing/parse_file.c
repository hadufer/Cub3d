/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:47:00 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 07:48:56 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	max_line_length(char *file)
{
	int	i;
	int	temp;
	int	max_line_length;

	i = -1;
	temp = 0;
	max_line_length = 0;
	while (file[++i])
	{
		if (file[i] != '\n')
			temp++;
		else
		{
			if (temp > max_line_length)
				max_line_length = temp;
			temp = 0;
		}
	}
	return (max_line_length);
}

int	max_column_length(char *file)
{
	int	i;
	int	max_column_length;

	i = -1;
	max_column_length = 0;
	while (file[++i])
		if (file[i] == '\n')
			max_column_length++;
	if (file[i] == '\0')
		max_column_length++;
	return (max_column_length);
}

void	fill_tab(char **file_da, char *file, int max_line)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = -1;
	while (file_da[++i])
	{
		j = -1;
		while (++j != max_line)
		{
			if (file[temp] != '\n')
				file_da[i][j] = file[temp];
			else
				file_da[i][j] = ' ';
			if (file[temp] != '\n' && file[temp])
				temp++;
		}
		if (file[temp] == '\n' && file[temp] != '\0')
			temp++;
	}
}

char	**get_file_in_tab(int max_line, int max_column, char *file)
{
	int		i;	
	char	**file_da;

	i = -1;
	file_da = malloc(sizeof(char *) * (max_column + 1));
	while (++i != max_column)
	{
		file_da[i] = malloc(sizeof(char) * (max_line + 1));
		ft_memset(file_da[i], ' ', max_line);
		file_da[i][max_line] = '\0';
	}
	file_da[i] = NULL;
	fill_tab(file_da, file, max_line);
	return (file_da);
}

char	**parse_file(char *path)
{
	char	*file;
	char	**file_da;

	file = get_file(path);
	file_da = get_file_in_tab(max_line_length(file),
			max_column_length(file), file);
	free(file);
	return (file_da);
}
