/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:13:21 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/14 19:42:50 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					len_list(t_tetri **tetri_list)
{
	int				len;
	t_tetri			*tmp;

	len = 0;
	tmp = *tetri_list;
	while (tmp->tetrimino)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void				create_elem(t_tetri **tetri, char count)
{
	t_tetri		*tmp;
	t_tetri		*elem;

	tmp = *tetri;
	if (!(elem = malloc(sizeof(t_tetri))))
		return ;
	elem->tetrimino = 0;
	tmp->index = 65 + count;
	tmp->next = elem;
}

void				tetri_size(uint16_t tetrimino, t_tetri *tetri)
{
	uint16_t		line;
	uint16_t		column;
	char			height;
	char			width;

	line = 0xF000;
	column = 0x8888;
	height = 0;
	width = 0;
	while (tetrimino & line)
	{
		height++;
		line >>= 4;
	}
	tetri->height = height;
	while (tetrimino & column)
	{
		width++;
		column >>= 1;
	}
	tetri->width = width;
}

void				do_list(t_tetri **tetri_list, int i)
{
	t_tetri			*tetri;

	tetri = *tetri_list;
	tetri->tetrimino = top_left(tetri->tetrimino);
	tetri_size(tetri->tetrimino, tetri);
	create_elem(&tetri, (i + 1) / 21);
}
