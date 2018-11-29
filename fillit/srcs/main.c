/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:13:50 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/14 19:52:44 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define VALID_CHAR(c) (c == '#' || c== '.' || c == '\n')

uint16_t			top_left(uint16_t tetrimino)
{
	while (!(tetrimino & 0xF000))
		tetrimino <<= 4;
	while (!(tetrimino & 0x8888))
		tetrimino <<= 1;
	return (tetrimino);
}

int					valid_map(int i, char c)
{
	if (c != '\n' || c != '\0')
	{
		if ((i + 1 - ((i + 1) / 21)) % 5 != 0)
			return (0);
	}
	if (c == '\n' || c == '\0')
	{
		if ((i + 2) % 21 != 0)
			return (0);
	}
	return (1);
}

int					tetri_taker(const char *str, t_tetri **tetri_list)
{
	uint16_t		i;
	int				count;
	t_tetri			*tetri;

	i = -1;
	count = 0;
	tetri = *tetri_list;
	while (str[++i] && VALID_CHAR(str[i]))
	{
		if (str[i] == '\n' && !valid_map(i, str[i + 1]))
			return (0);
		if (str[i] == '#')
			take_power(&tetri, i, count++);
		if (((i + 2) % 21 == 0 && count % 4 == 0 && count != 0))
		{
			if (valid_shape(top_left(tetri->tetrimino)))
			{
				do_list(&tetri, i);
				tetri = tetri->next;
			}
			else
				return (0);
		}
	}
	return (str[i + 1] == '\0' ? 1 : 0);
}

int					main(int ac, char **av)
{
	int				fd;
	char			buf[BUF_SIZE];
	char			*str;
	int				ret;
	t_tetri			*tetri_list;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if ((ret = read(fd, buf, BUF_SIZE)))
		str = ft_strdup(buf);
	close(fd);
	if (!(tetri_list = malloc(sizeof(t_tetri))))
		return (0);
	tetri_list->tetrimino = 0;
	if (!ret || !tetri_taker(str, &tetri_list))
	{
		write(2, "error\n", 6);
		return (0);
	}
	main_solve(tetri_list);
	return (0);
}
