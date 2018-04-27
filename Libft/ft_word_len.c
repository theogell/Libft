/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:24:50 by theogell          #+#    #+#             */
/*   Updated: 2018/04/20 22:47:09 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_word_len(char const *s, char c)
{
	size_t	i;
	size_t	nb_char;

	i = 0;
	nb_char = 0;
	while (s[i] != c && s[i])
	{
		if (s[i] != c && s[i + 1] != c)
			nb_char++;
		i++;
	}
	nb_char++;
	return (nb_char);
}
