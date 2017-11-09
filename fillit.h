/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:49 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/08 23:03:00 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_fill
{
	char			**tetri;
	char			alpha;
	struct s_fill	*next;
	struct s_fill	*prev;
	int				height;
	int				length;
}					t_fill;

typedef struct		s_map
{
	char			**megamap;
	int				size;
}					t_map;

/*
** Recursive functions
*/

void				final_map(t_map *map);
void				place_dots(t_fill *lst, t_map *map, int x, int y);
void				place_tet(t_fill *lst, t_map *map, int x, int y);
int					check_tet_fit(t_fill *lst, t_map *map, int x, int y);
int					backtrack_solve(t_map *map, t_fill *begin_fill);

/*
**store and trim tets
*/

char				**trim_tetri(t_fill *lst);
char				**trim_rows(char **tetri);
char				**trim_col(char **tetri, t_fill *lst);

/*
** get tet coordinates
*/

int					get_bottom(t_fill *l_tetri);
int					get_right(t_fill *l_tetri);
void				find_height(t_fill *tetri);
int					get_top(t_fill *l_tetri);
int					get_left(t_fill *l_tetri);

/*
** Count stored tets and adjust map size
*/

t_map				*adjust_map(t_fill *begin_fill);
int					size_map(t_fill *lst);
t_map				*finalmap(int size);
int					count_tet(t_fill *begin_fill);

/*
** check for errors in read files / tets
*/

int					ft_verif(char *form);
int					is_tetri(char *str, int i, int x);
int					check_chars(char *str);

/*
** initialize map, update fill list, and check for remaining errors
*/

char				**map(char *str);
t_fill				*fill_map(char *str, int len);
t_fill				*add_map(char *str, t_fill *ifill, char c);

/*
** main functions: print error message and start backtracking solutions after
** reading tet files and storing in linked list
*/

void				primary_function(char *buf, int ret);
void				ft_found_error(char *str);

/*
** read files from stdin
*/

void				ft_read(char *file);

#endif
