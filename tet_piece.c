/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:03:56 by labrown           #+#    #+#             */
/*   Updated: 2017/10/24 00:25:30 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/* 
** create tetris piece
*/

t_tet	new_tetris(char **place, int width, int heigth, char letter)
{
	t_tet	*piece;

	piece = ft_memalloc(sizeof(t_tet));
	piece->width = width;
	piece->heigth = heigth;
	piece->value = letter;
	piece->place = place;
	return (piece);
}

/*
** create a point
*/

t_point	new_point(int x, int y)
{
	t_point	*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

/*
** free the memory allocated for tet piec
*/

void	free_tetpiece(t_tet *piece)
{
	int	height;

	height = 0;
	while (height < piece->height)
		ft_memdel((void **)(&(piece->place[height++])));
	ft_memdel((void **)&(piece->place));
	ft_memdel((void **)&piece);
	return ;
}

/*
** free the list holding the read pieces
*/

void	free_read_pcs(t_list *list)
{
	t_tet	*piece;
	t_list	*nxt;

	while (list)
	{
		piece = (t_tet *)list->content;
		nxt= list->next;
		free_tetpiece(piece);
		ft_memdel((void **)&list);
		list = nxt;
	}
	return (NULL);
}
