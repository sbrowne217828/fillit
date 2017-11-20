/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:28 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/19 15:34:38 by labrown          ###   ########.fr       */
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
	t_map		*map;
	t_tetlst	*tets;

	tets = NULL;
	if (ft_verif(buf) == 1)
	{
		tets = tet_lst(buf, ret);
		find_height(tets);
		trim_tetri(tets);
		map = adjust_map(tets);
		final_map(map);
	}
	else
	{
		ft_putstr("error\n");
	}
}

void	ft_read(char *file)
{
	int		fd;
	int		ret;
	char	*buf;

	if (!(buf = malloc(sizeof(char*) * 548)))
		return ;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_found_error("error\n");
	ret = read(fd, buf, 547);
	if (ret > 546)
		ft_found_error("error\n");
	if (buf[ret - 1] == '\n' && buf[ret - 2] == '\n')
		ft_found_error("error\n");
	buf[ret] = '\0';
	if (close(fd) == -1)
		ft_found_error("error\n");
	primary_function(buf, ret);
	(buf) ? free(buf) : (0);
}

int		main(int c, char **v)
{
	if (c != 2)
		ft_putstr_fd("usage : ./fillit [target_file]\n", 2);
	else
		ft_read(v[1]);
	return (0);
}
