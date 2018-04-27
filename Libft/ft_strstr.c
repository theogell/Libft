/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 02:30:32 by theogell          #+#    #+#             */
/*   Updated: 2018/04/09 21:37:32 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	const char	*big;
	const char	*little;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			big = haystack + 1;
			little = needle + 1;
			while (*little && *little == *big)
			{
				little++;
				big++;
			}
			if (!*little)
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
