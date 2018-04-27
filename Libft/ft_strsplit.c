/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theogell <theogell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:03:10 by theogell          #+#    #+#             */
/*   Updated: 2018/04/16 23:29:31 by theogell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb_word;
	size_t	nb_char;
	char	**tab;

	i = -1;
	j = 0;
	nb_word = ft_word_count(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_word + 1))))
		return (NULL);
	tab[nb_word] = NULL;
	while (++i < nb_word)
	{
		while (s[j] == c)
			j++;
		if (s[j] != c)
		{
			nb_char = ft_word_len(&s[j], c);
			tab[i] = ft_strnew(sizeof(char) * (nb_char + 1));
			ft_strncpy(tab[i], &s[j], nb_char);
		}
		j = j + nb_char;
	}
	return (tab);
}
