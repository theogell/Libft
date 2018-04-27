/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:46:02 by theogell          #+#    #+#             */
/*   Updated: 2018/04/20 19:22:41 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*new;
	const char	*start;
	const char	*end;

	if (!s)
		return (NULL);
	while ((*s != 0 || *s < 32) && (*s == '\t' || *s == ' ' || *s == '\n'))
		++s;
	start = s;
	while (*s)
		s++;
	while ((s != start) && (*(--s) == '\t' || *s == ' ' || *s == '\n'))
		;
	if (!(new = (char *)malloc(sizeof(char) * (((s + 1) - start) + 1))))
		return (0);
	end = new;
	while (start != (s + 1))
		*new++ = *start++;
	*new = '\0';
	return ((char *)end);
}
