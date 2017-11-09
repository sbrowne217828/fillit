/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:06 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/08 23:04:59 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tet(t_fill *begin_fill)
{
	t_fill	*l_fill;

	l_fill = begin_fill->prev;
	return (l_fill->alpha - 64);
}

t_map	*finalmap(int size)
{
	int		i;
	int		j;
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map) * size)))
		return (NULL);
	map->size = size;
	if (!(map->megamap = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	j = 0;
	while (j < size)
	{
		if (map->megamap[j])
			free(map->megamap[j]);
		map->megamap[j] = ft_strnew(size);
		i = 0;
		while (i < size)
		{
			map->megamap[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}

int		size_map(t_fill *lst)
{
	int		a;
	int		size;

	a = 2;
	while ((a * a) < count_tet(lst) * 4)
		a++;
	size = a;
	return (size);
}

t_map	*adjust_map(t_fill *begin_fill)
{
	t_map	*map;
	int		size;

	map = NULL;
	size = size_map(begin_fill);
	map = finalmap(size);
	while (backtrack_solve(map, begin_fill) == 0)
	{
		size++;
		map = finalmap(size);
	}
	return (map);
}
