/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:08:33 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 08:32:59 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_dir(t_coords *coords)
{
	coords->i = 0;
	coords->j = 0;
}

void	init_coords(t_texture_coords *texture_coords)
{
	init_dir(&texture_coords->no);
	init_dir(&texture_coords->so);
	init_dir(&texture_coords->ea);
	init_dir(&texture_coords->we);
	init_dir(&texture_coords->f);
	init_dir(&texture_coords->c);
}
