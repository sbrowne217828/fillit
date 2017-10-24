/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 13:49:57 by labrown           #+#    #+#             */
/*   Updated: 2017/10/23 22:50:51 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <libft.h>

int		main(int c, char **v)
{
	t_list	*piece_list;
	t_map	*final_map;

	if (c != 2)
	{
		ft_putstr("Only two argc's allowed: ./a.out and fillit\n");
		return (1);
	}
	if (piece_list = open(v[1], O_RDONLY) == NULL)
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	final_map = solve(piece_list);
	print_map(final_map);
	del_map(final_map);
	free_list(piece_list);
	return (0);
}
