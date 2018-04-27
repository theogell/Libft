/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 18:59:54 by theogell          #+#    #+#             */
/*   Updated: 2018/04/13 19:02:49 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char const *s, int fd)
{
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
