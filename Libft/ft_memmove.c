/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 21:55:46 by theogell          #+#    #+#             */
/*   Updated: 2018/04/21 16:14:24 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	size_t			i;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	i = 0;
	if (psrc < pdst)
	{
		while (len--)
			*(pdst + len) = *(psrc + len);
	}
	else
	{
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}
