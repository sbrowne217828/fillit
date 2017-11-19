/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:00 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/18 23:26:16 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**trim_row(char **tetri)
{
	int y;
	int y_end;

	y = 3;
	while (!ft_strchr(tetri[0], '#'))
	{
		y_end = 0;
		while (y_end < 3)
		{
			tetri[y_end] = tetri[y_end + 1];
			y_end++;
		}
		tetri[3] = "....";
	}
	while (y >= 0)
	{
		if (!ft_strchr(tetri[y], '#'))
			tetri[y] = "....";
		y--;
	}
	return (tetri);
}

char		**trim_col(char **tetri, t_tetlst *lst)
{
	int x;
	int y;

	y = 0;
	x = 0;
	while (tetri[0][0] == '.' && tetri[1][0] == '.' && tetri[2][0] == '.'
			&& tetri[3][0] == '.' && x < 4)
	{
		y = 0;
		if (tetri[1][x] == '.' && tetri[2][x] == '.' && tetri[3][x] == '.'
				&& tetri[0][x] == '.' && x <= 3)
		{
			while (y < lst->height)
			{
				tetri[y][0] = tetri[y][1];
				tetri[y][1] = tetri[y][2];
				tetri[y][2] = tetri[y][3];
				tetri[y][3] = '.';
				y++;
			}
		}
		x++;
	}
	return (tetri);
}

char		**trim_tetri(t_tetlst *lst)
{
	char **tet;

	if (!(tet = malloc(sizeof(char*) * 4)))
		return (NULL);
	while (lst)
	{
		trim_row(lst->tetri);
		trim_col(lst->tetri, lst);
		lst = lst->next;
	}
	return (tet);
}
