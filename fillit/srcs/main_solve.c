/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:56:41 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/14 20:27:06 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void				ft_delete(uint16_t tetrimino, uint16_t **map, int pos,
		int size)
{
	uint16_t		*tmp;
	uint16_t		line;
	int				i;
	int				x;
	int				y;

	tmp = *map;
	i = 0;
	line = 0xF000;
	x = pos / size;
	y = pos % size;
	while (y < size && i < 4)
	{
		tmp[y] = (((tetrimino & line) << (4 * i) >> x)) ^ tmp[y];
		i++;
		y++;
		line >>= 4;
	}
}

void				ft_place(uint16_t tetrimino, uint16_t **map, int pos,
		int size)
{
	uint16_t		*tmp;
	uint16_t		line;
	int				i;
	int				x;
	int				y;

	i = 0;
	line = 0xF000;
	tmp = *map;
	x = pos / size;
	y = pos % size;
	while (y < size && i < 4)
	{
		tmp[y] = (((tetrimino & line) << (4 * i)) >> x) ^ tmp[y];
		i++;
		y++;
		line >>= 4;
	}
}

int					check(uint16_t tetrimino, uint16_t **map, int pos, int size)
{
	uint16_t	*tmp;

	tmp = *map;
	if ((((tetrimino & 0xF000) >> (pos / size)) ^ tmp[pos % size]) ==
		(((tetrimino & 0xF000) >> (pos / size)) + tmp[pos % size]))
	{
		if (((((tetrimino & 0xF00) << 4) >> (pos / size)) ^
			tmp[(pos % size) + 1]) == ((((tetrimino & 0xF00) << 4) >>
			(pos / size)) + tmp[(pos % size) + 1]))
		{
			if (((((tetrimino & 0xF0) << 8) >> (pos / size)) ^
				tmp[(pos % size) + 2]) == ((((tetrimino & 0xF0) << 8) >>
				(pos / size)) + tmp[(pos % size) + 2]))
			{
				if (((((tetrimino & 0xF) << 12) >> (pos / size)) ^
					tmp[(pos % size) + 3]) == ((((tetrimino & 0xF) << 12) >>
					(pos / size)) + tmp[(pos % size) + 3]))
				{
					ft_place(tetrimino, map, pos, size);
					return (1);
				}
			}
		}
	}
	return (0);
}

int					ft_solve(t_tetri *tetri, uint16_t **map, int size,
		char ***display_map)
{
	int				x;
	int				y;
	t_tetri			*tmp;

	y = -1;
	tmp = tetri;
	if (tetri == NULL)
		return (1);
	while (++y <= size - tmp->height)
	{
		x = -1;
		while (++x <= size - tmp->width)
		{
			if (check(tmp->tetrimino, map, (size * x) + y, size))
			{
				if (ft_solve(tmp->next, map, size, display_map))
				{
					fill(display_map, tmp, x, y);
					return (1);
				}
				ft_delete(tmp->tetrimino, map, (size * x) + y, size);
			}
		}
	}
	return (0);
}

void				main_solve(t_tetri *tetri_list)
{
	int				size;
	uint16_t		*map;
	char			**display_map;

	size = ft_sqrt(4 * len_list(&tetri_list));
	if (!(display_map = (char **)malloc(sizeof(char *) * 16)))
		return ;
	grid(&display_map);
	if (!(map = (uint16_t *)malloc(sizeof(uint16_t) * 16)))
		return ;
	ft_memset((void*)map, 0, size);
	while (!ft_solve(tetri_list, &map, size, &display_map))
	{
		ft_memset((void*)map, 0, size);
		size++;
	}
	ft_display(display_map, size);
}
