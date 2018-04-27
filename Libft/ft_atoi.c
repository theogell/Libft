/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:32:23 by theogell          #+#    #+#             */
/*   Updated: 2018/04/09 21:35:34 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		res;
	int		neg;
	uint8_t	digit;

	res = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		neg = (*str == '-' ? -1 : 1);
		str++;
	}
	while ((digit = ft_todigit(*str)) <= 9U)
	{
		res = res * 10 + digit;
		str++;
	}
	return (res * neg);
}
