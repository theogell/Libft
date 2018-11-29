/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:44:06 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/14 19:45:26 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdlib.h>

void				fill(char ***map, t_tetri *tetri, int x, int y)
{
	uint16_t		mask;
	int				i;
	int				pos;
	uint16_t		line;
	char			**tmp;

	tmp = *map;
	line = 0xF000;
	i = 0;
	while (i < 4)
	{
		mask = 0x8000;
		pos = 0;
		while (mask > 0x800)
		{
			if (((tetri->tetrimino & line) << (4 * i)) & mask)
				tmp[y][x + pos] = tetri->index;
			pos++;
			mask >>= 1;
		}
		y++;
		i++;
		line >>= 4;
	}
}

void				grid(char ***display_map)
{
	char			**tmp;
	int				x;
	int				y;

	tmp = *display_map;
	y = 0;
	while (y < 16)
	{
		if (!(tmp[y] = (char *)malloc(sizeof(char) * 17)))
			return ;
		x = 0;
		while (x < 16)
		{
			tmp[y][x] = '.';
			x++;
		}
		tmp[y][x] = '\0';
		y++;
	}
}
