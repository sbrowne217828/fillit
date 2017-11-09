/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:11 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/08 23:06:53 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**map(char *str)
{
	int		i;
	int		dim;
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * (4))))
		return (NULL);
	dim = 0;
	i = 0;
	while (dim < 4)
	{
		if (!(tab[dim] = malloc(sizeof(char) * 5)))
			return (NULL);
		ft_strncpy(tab[dim], str + i, 4);
		tab[dim][4] = '\0';
		i += 5;
		dim++;
	}
	return (tab);
}

t_fill	*add_map(char *str, t_fill *init_fill, char c)
{
	if (!(init_fill = (t_fill*)malloc(sizeof(*init_fill))))
		return (NULL);
	init_fill->tetri = map(str);
	init_fill->alpha = c;
	init_fill->next = NULL;
	return (init_fill);
}

t_fill	*fill_map(char *str, int len)
{
	t_fill	*nx_fill;
	t_fill	*init_fill;
	int		i;
	char	c;

	i = 21;
	c = 'A';
	if (!(nx_fill = (t_fill*)malloc(sizeof(*nx_fill))))
		return (NULL);
	nx_fill->tetri = map(str);
	nx_fill->alpha = c;
	nx_fill->next = NULL;
	nx_fill->prev = nx_fill;
	init_fill = nx_fill;
	while (i < len)
	{
		c++;
		init_fill->next = add_map(str + i, init_fill, c);
		init_fill->prev = init_fill;
		init_fill = init_fill->next;
		i += 21;
	}
	init_fill->next = NULL;
	nx_fill->prev = init_fill;
	return (nx_fill);
}
