/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:16:19 by theogell          #+#    #+#             */
/*   Updated: 2018/04/09 21:47:35 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	dest = (char*)dst;
	source = (char*)src;
	if (n == 0 || dst == src)
		return (dst);
	while (n--)
	{
		*dest = *source;
		dest++;
		source++;
	}
	return (dst);
}
