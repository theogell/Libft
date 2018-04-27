/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 03:37:38 by theogell          #+#    #+#             */
/*   Updated: 2018/04/10 04:23:11 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *str;

	str = (unsigned const char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void*)str);
		str++;
	}
	return (NULL);
}
