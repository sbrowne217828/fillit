/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:40:09 by labrown           #+#    #+#             */
/*   Updated: 2017/10/20 21:35:16 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
** check and set the tetrimino boundaries within a file
*/

void	tet_shape(char *s, t_pos *min, t_pos *max)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i / 5 < min->y)
			min->y = i / 5;
		if (i / 5 > max->y)
			max->y = i / 5;
		if (i % 5 < min->x)
			min->x = i % 5;
		if (i % 5 > max->x)
			max->x = i % 5;
	}
	i++;
}

/*
** read a tetrimino from a valid file chunk and allocate a struct for it
*/

t_tet	*read_tet(char *s, char value)
{
	int			i;
	t_point		sm;
	t_point		b;
	char		**place;
	t_tet		*tetrip;

	i = 0;
	sm = new_point(3, 3);
	b = new_point(0, 0);
	tet_shape(s, sm, b);
	place = ft_memalloc(sizeof(char *) * (b->y - sm->y +1));
	while (i < b->y - sm->y + 1)
	{
		place[i] = ft_strnew(b->y - sm->y + 1);
		ft_strncpy(place[i], s + (sm->x) + (i + sm->y) * 5, b->x - sm->x + 1);
		i++;
	}
	tetrip = new_tetri(place, b->x - sm->x + 1, b->y - sm->y + 1, value);
	ft_memdel((void **)&sm);
	ft_memdel((void **)&b);
	return (tetrip);
}

/*
**check connections within tetriminoes 6-8 connections for valid pieces
*/

int		check_cnx(char *s)
{
	int		i;
	int		cnx;
	
	i = 0;
	cnx = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i + 1 < 20 && s[i + 1] == '#')
				cnx++;
			if (i - 1 >= 0 && s[i - 1] == '#')
				cnx++;
			if (i + 5 < 20 && s[i + 5] == '#')
				cnx++;
			if (i - 5 >= 0 && s[i - 5] == '#')
				cnx++;
		}
	}
	return (cnx == 8 || cnx == 6);
}

/*
**check character counts should be less than 21 total
*/

int		check_count(char *s, int c)
{
	int		i;
	int		b;

	i = 0;
	b = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (s[i] == '#' || s[i] == '.')
				return (1);
			if (s[i] == '#' && ++b > 4)
				return (2);
		}
		else if (s[i] != '\n')
			return (3);
		i++;
	}
	if (s[20] != '\n' && c == 21)
		return (4);
	if (!check_cnx(s))
		return (5);
	return (0);
}

/*
**read files from fd
*/

t_list	*read_files(int fd)
{
	int		c;
	char	*hold;
	char	crnt;
	t_list	*list;
	t_tet	*piece;

	hold = ft_strnew(21);
	list = NULL;
	crnt = 'A';
	while ((c = read(fd, hold, 21)) >= 20)
	{
		if (check_count(hold, c) != 0 || read_tet(hold, crnt++) == NULL)
		{
			ft_memdel((void **)&hold);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(piece, sizeof(t_tet)));
		ft_memdel((void **)&piece);
	}
	ft_memdel((void **)&hold);
	if (!c)
		return(free_list(list));
	ft_revlst(&list);
	return (list);
}
