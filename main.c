/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:28 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/09 16:30:53 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_found_error(char *fail)
{
	ft_putstr(fail);
	exit(0);
}

void	primary_function(char *buf, int ret)
{
	t_fill	*begin_fill;
	t_map	*map;

	begin_fill = NULL;
	if (ft_verif(buf) == 1)
	{
		begin_fill = fill_map(buf, ret);
		find_height(begin_fill);
		trim_tetri(begin_fill);
		map = adjust_map(begin_fill);
		final_map(map);
		free(buf);
	}
	else
	{
		ft_putstr("error\n");
		free(buf);
	}
}

int		main(int c, char **v)
{
	if (c != 2)
		ft_putstr_fd("usage : ./fillit [target_file]\n", 2);
	else
		ft_read(v[1]);
	return (0);
}
