/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:24:21 by theogell          #+#    #+#             */
/*   Updated: 2018/04/09 21:36:02 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*tmp;

	tmp = b;
	while (len--)
	{
		*tmp = (unsigned char)c;
		tmp++;
	}
	return (b);
}
