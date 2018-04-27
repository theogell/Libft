/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 18:37:04 by theogell          #+#    #+#             */
/*   Updated: 2018/04/27 19:31:54 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

static void		check_file(int fd)
{
	int			ret;
	char		buf;
	char const	*str;

	str = ft_strnew(0);
	while ((ret = read(fd, &buf, 1)))
		str = ft_strjoin(str, &buf);
	ft_putstr(str);	
}

int				main(int ac, char **av)
{
	int			fd;

	if (ac != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	check_file(fd);
	return (0);
}
