/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:45:13 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/14 19:55:08 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const uint16_t		g_shape[20] = {
	0xC880,
	0x44C0,
	0x88C0,
	0xC440,
	0xE800,
	0xE200,
	0x8E00,
	0x2E00,
	0x4E00,
	0x4C40,
	0x8C80,
	0xE400,
	0xCC00,
	0x8888,
	0xF000,
	0x8C40,
	0x4C80,
	0x6C00,
	0xC600
};

int					valid_shape(uint16_t tetri)
{
	int i;

	i = -1;
	while (++i < 20)
	{
		if (tetri == g_shape[i])
			return (tetri);
	}
	return (0);
}