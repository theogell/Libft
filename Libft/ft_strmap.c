/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:48:31 by theogell          #+#    #+#             */
/*   Updated: 2018/04/11 18:25:39 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*n_str;
	size_t	i;

	if (!f || !s)
		return (NULL);
	i = 0;
	n_str = malloc(ft_strlen(s) + 1);
	if (!n_str)
		return (NULL);
	while (s[i])
	{
		n_str[i] = f(s[i]);
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}
