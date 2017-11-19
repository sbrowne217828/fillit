/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:06 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/19 02:33:37 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tet(t_tetlst *tets)
{
	t_tetlst	*last_tet;

	last_tet = tets->prev;
	return (last_tet->alpha - 64);
}

t_map	*create_map(int size)
{
	int		i;
	int		j;
	t_map	*map;

	if (!(map = malloc(sizeof(t_map) * size)))
		return (NULL);
	map->size = size;
	if (!(map->megamap = malloc(sizeof(char*) * size)))
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

int		size_map(t_tetlst *lst)
{
	int		a;
	int		size;

	a = 2;
	while ((a * a) < count_tet(lst) * 4)
		a++;
	size = a;
	return (size);
}

t_map	*adjust_map(t_tetlst *tets)
{
	t_map	*map;
	int		size;

	map = NULL;
	size = size_map(tets);
	map = create_map(size);
	while (backtrack_solve(map, tets) == 0)
	{
		size++;
		map = create_map(size);
	}
	return (map);
}
