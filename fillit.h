/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 13:04:49 by labrown           #+#    #+#             */
/*   Updated: 2017/10/22 20:58:35 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"

typedef struct		s_map
{
	int		size;
	char	**array;
}					t_map

typedef struct		s_tet
{
	int		width;
	int		heigth;
	char	**place;
	char	value;
}					t_tet

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point

t_list				*read_files(int fd);
int					check_count(char *s, int c);
int					check_cnx(char *s);
t_tet				*read_tet(char *s, char value);
void				tet_shape(char *s, t_pos *min, t_pos *max);
t_map				build_map(int sz);
void				print_map(t_map *map);
void				del_map(t_map *map);
