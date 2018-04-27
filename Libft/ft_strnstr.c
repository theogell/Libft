/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 22:07:22 by theogell          #+#    #+#             */
/*   Updated: 2018/04/20 17:09:32 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*little;
	const char	*big;
	size_t		size;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len--)
	{
		if (*needle == *haystack)
		{
			little = needle + 1;
			big = haystack + 1;
			size = len;
			while (size-- && *little && *little == *big)
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
