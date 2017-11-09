/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:37:32 by gtavares          #+#    #+#             */
/*   Updated: 2017/09/25 12:37:39 by gtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_create_tab(const char *s, char c,
		int nb_word, int max_len_word)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char **)malloc(sizeof(*tab) * nb_word + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(tab[j] = (char *)malloc(sizeof(**tab) * max_len_word + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		nb_word;
	int		len_word;
	int		max_len_word;

	if (!s || !c)
		return (NULL);
	i = 0;
	nb_word = 0;
	max_len_word = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			nb_word++;
			len_word = 0;
			while (s[i] != c && s[i++])
				len_word++;
			if (len_word > max_len_word)
				max_len_word = len_word;
		}
	}
	return (ft_create_tab(s, c, nb_word, max_len_word));
}
