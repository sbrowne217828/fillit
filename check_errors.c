/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:51 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/17 15:08:45 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_tetri(char *str, int i, int x)
{
	int bd;

	bd = 0;
	while (str[i] && str[i] != '#' && x < 21)
	{
		i++;
		x++;
	}
	if (str[i] == '#' && x < 21)
	{
		if (str[i + 1] == '#' && str[i + 1])
			bd++;
		if (str[i - 1] == '#' && i > 0 && x > 0)
			bd++;
		if (str[i - 5] == '#' && x > 4)
			bd++;
		if (str[i + 5] == '#' && str[i + 5] && x < 14)
			bd++;
	}
	if (str[i + 1] && x < 21)
		return (bd + is_tetri(str, i + 1, x + 1));
	return (bd);
}

int		check_chars(char *str)
{
	int c;
	int i;

	c = 0;
	i = 0;
	while (str[i] && (i % 21 != 0 || i == 0))
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
		{
			ft_found_error("error\n");
		}
		c += (str[i] == '#' ? 1 : 0);
		if ((i % 5 == 4 || i == 20) && str[i] != '\n')
			return (1);
		if ((i % 5 != 4 && i != 20) && str[i] == '\n')
			return (1);
		i++;
	}
	if (str[i + 1] != '\0' && c == 4)
		return (c + check_chars(str + i));
	return (c);
}

int		ft_verif(char *form)
{
	int i;

	i = 21;
	if (check_chars(form) % 4 == 0)
	{
		if (is_tetri(form, 0, 0) != 6 && is_tetri(form, 0, 0) != 8)
			return (0);
		while (form[i])
		{
			if (is_tetri(form, i, 0) != 6 && is_tetri(form, i, 0) != 8)
				return (0);
			i += 21;
		}
		return (1);
	}
	return (0);
}
