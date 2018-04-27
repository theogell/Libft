/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:55:39 by theogell          #+#    #+#             */
/*   Updated: 2018/04/20 23:13:12 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_negative(int *c, int *neg)
{
	if (*c < 0)
	{
		*c *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int c)
{
	char		*str;
	int			i;
	int			nb;
	int			neg;

	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	neg = 0;
	ft_itoa_negative(&c, &neg);
	nb = c;
	while (c /= 10)
		i++;
	i += neg;
	if ((str = (char*)malloc(sizeof(*str) * i + 1)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
