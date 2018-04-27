/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:07:31 by theogell          #+#    #+#             */
/*   Updated: 2018/04/16 20:10:05 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_word;

	i = 0;
	nb_word = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			nb_word++;
			while (s[i] != c && s[i + 1])
				i++;
		}
		i++;
	}
	return (nb_word);
}
