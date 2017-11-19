/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:11 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/19 02:50:03 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tet(char *str)
{
	int		i;
	int		dim;
	char	**tet;

	if (!(tet = malloc(sizeof(char *) * (4))))
		return (NULL);
	dim = 0;
	i = 0;
	while (dim < 4)
	{
		if (!(tet[dim] = malloc(sizeof(char) * 5)))
			return (NULL);
		ft_strncpy(tet[dim], str + i, 4);
		tet[dim][4] = '\0';
		i += 5;
		dim++;
	}
	return (tet);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
		ft_memdel((void **)&(map->megamap[i++]));
	ft_memdel((void **)&(map->megamap));
	ft_memdel((void **)&map);
}

t_tetlst	*add_tet(char *str, t_tetlst *init_tet, char c)
{
	//if (!(init_tet = malloc(sizeof(*init_tet))))
	//	return (NULL);
	init_tet->tetri = tet(str);
	init_tet->alpha = c;
	init_tet->next = NULL;
	return (init_tet);
}

t_tetlst	*tet_lst(char *str, int len)
{
	t_tetlst	*nx_tet;
	t_tetlst	*init_tet;
	int			i;
	char		c;

	i = 21;
	c = 'A';
	if (!(nx_tet = malloc(sizeof(*nx_tet))))
		return (NULL);
	nx_tet->tetri = tet(str);
	nx_tet->alpha = c;
	nx_tet->next = NULL;
	nx_tet->prev = nx_tet;
	init_tet = nx_tet;
	while (i < len)
	{
		c++;
		init_tet->next = add_tet(str + i, init_tet, c);
		init_tet->prev = init_tet;
		init_tet = init_tet->next;
		i += 21;
	}
	init_tet->next = NULL;
	nx_tet->prev = init_tet;
	return (nx_tet);
}
