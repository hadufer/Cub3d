/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:46:03 by nferre            #+#    #+#             */
/*   Updated: 2022/03/29 11:40:14 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_tab(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

void	print_color(t_color color)
{
	printf("r : %d\n", color.r);
	printf("g : %d\n", color.g);
	printf("b : %d\n", color.b);
}

void	print_int_tab(int *tab, int x, int y)
{
	int	i;

	i = -1;
	while (++i != x * y)
	{
		printf("%d", tab[i]);
		if (i % x == x - 1)
			printf("\n");
	}
}