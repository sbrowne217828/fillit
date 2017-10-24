/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:28:33 by labrown           #+#    #+#             */
/*   Updated: 2017/10/23 19:32:13 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** create map
*/

t_map	build_map(int sz)
{
	int		a;
	int		b;
	t_map	*map;

	a = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = sz;
	map->array = (char **)ft_memalloc(sizeof(char *) * sz);
	while (a < sz)
	{
		b = 0;
		map->array[a] = ft_strnew(sz);
		while (b < sz)
			map->array[a][b++] = '.';
		a++;
	}
	return (map);
}

/*
** print map to standard output
*/

void	print_map(t_map *map)
{
	int	a;

	a = 0;
	while (a < map->size)
	{
		ft_putstr(map->array[a]);
		ft_putchar('\n');
		a++;
	}
	return ;
}

/*
** delete map and memmory allocated for map
*/

void	del_map(t_map *map)
{
	int	a;

	a = 0;
	while (a < map->size)
		ft_memdel((void **)map->array[a++])
	ft_memdel((void **)&map->array);
	ft_memdel((void **)&map);
	return ;
}

/*
** check if their is an opening on the map for a tetrimino at position x,y
*/

int		chk_pos(t_tet *tet, int x, int y, t_map *map)
{
	int	a;
	int	b;

	a = 0;
	while (a < tet->heigth)
	{
		b = 0;
		while (b < tet->width)
		{
			if (tet->place[a][b] == '#' && map->array[a + y][b + x] != '.')
				return (0);
			b++;
		}
		a++;
	}
	place_tet(tet, map, new_point(x, y), tet->value);
	return (1);
}

/*
** place tet at specified character if their is an opening 
*/

void	place_tet(t_tet *tet, t_map *map, t_point *point, char c)
{
	int	a;
	int	b;

	a = 0;
	while (a < tet->heigth)
	{
		b = 0;
		while (b < tet->width)
		{
			if (tet->place[a][b] == '#')
				map->array[point->y + a][point->x + b] = c;
			b++;
		}
		a++;
	}
	ft_memdel((void **)&point);
}

