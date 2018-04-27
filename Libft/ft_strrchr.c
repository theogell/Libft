/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 01:55:03 by theogell          #+#    #+#             */
/*   Updated: 2018/04/20 16:46:33 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	const char	*t;

	t = s;
	while (*s)
		s++;
	while (*s != *t && *s != c)
		s--;
	return (*s == c ? (char*)s : NULL);
}
