/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:20 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/18 18:55:57 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	final_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putendl(map->megamap[i]);
		i++;
	}
}

int		backtrack_solve(t_map *map, t_tetlst *lst)
{
	int			x;
	int			y;
	t_tetlst	*tets;

	
	if (lst == NULL)
		return (1);
	y = 0;
	tets = lst;
	while (y <= map->size - tets->height)
	{
		x = 0;
		while (x <= map->size - tets->length)
		{
			if (check_tet_fit(tets, map, x, y))
			{
				if (backtrack_solve(map, tets->next))
					return (1);
				else
					place_dots(tets, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		check_tet_fit(t_tetlst *lst, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < lst->height)
	{
		i = 0;
		while (i < lst->length)
		{
			if (lst->tetri[j][i] == '#' && map->megamap[y + j][x + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	place_tet(lst, map, x, y);
	return (1);
}

void	place_tet(t_tetlst *lst, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < lst->height)
	{
		i = 0;
		while (i < lst->length)
		{
			if (lst->tetri[j][i] == '#')
				map->megamap[y + j][x + i] = lst->alpha;
			i++;
		}
		j++;
	}
}

void	place_dots(t_tetlst *lst, t_map *map, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < lst->height)
	{
		i = 0;
		while (i < lst->length)
		{
			if (lst->tetri[j][i] == '#')
				map->megamap[y + j][x + i] = '.';
			i++;
		}
		j++;
	}
}
