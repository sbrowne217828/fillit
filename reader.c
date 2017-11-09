/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:39 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/08 23:04:32 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
}
