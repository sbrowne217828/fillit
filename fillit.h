/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtavares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:52:49 by gtavares          #+#    #+#             */
/*   Updated: 2017/11/19 22:18:08 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef	struct		s_tetlst
{
	char			**tetri;
	char			alpha;
	struct s_tetlst	*next;
	struct s_tetlst	*prev;
	int				height;
	int				length;
}					t_tetlst;

typedef struct		s_map
{
	char			**megamap;
	int				size;
}					t_map;

/*
** Recursive functions
*/

void				final_map(t_map *map);
void				place_dots(t_tetlst *lst, t_map *map, int x, int y);
void				place_tet(t_tetlst *lst, t_map *map, int x, int y);
int					check_tet_fit(t_tetlst *lst, t_map *map, int x, int y);
int					backtrack_solve(t_map *map, t_tetlst *begin_fill);

/*
**store and trim tets
*/

char				**trim_tetri(t_tetlst *lst);
char				**trim_rows(char **tetri);
char				**trim_col(char **tetri, t_tetlst *lst);

/*
** get_tet coordinates for storage
*/

int					get_bottom(t_tetlst *l_tetri);
int					get_right(t_tetlst *l_tetri);
void				find_height(t_tetlst *tetri);
int					get_top(t_tetlst *l_tetri);
int					get_left(t_tetlst *l_tetri);

/*
** map.c stored tets and adjust map size
*/

t_map				*adjust_map(t_tetlst *tets);
int					size_map(t_tetlst *lst);
t_map				*create_map(int size);
int					count_tet(t_tetlst *tets);

/*
** check_errors.c: check for errors in read files / tets
*/

int					ft_verif(char *form);
int					is_tetri(char *str, int i, int x);
int					check_chars(char *str);

/*
** tet.c: initialize map, update tet list, and check for remaining
** errors
*/

char				**new_tet(char *str);
t_tetlst			*tet_lst(char *str, int len);
t_tetlst			*add_tet(char *str, t_tetlst *ifill, char c);

/*
** free.c be so free the world hates you
*/
void				free_map(t_map *map);
void				free_tet(char **tet);
void				free_tetlst(t_tetlst *lst);

/*
** main.c functions: print error message and initialize backtracking
** solutions after reading tet files and storing in linked list
*/

void				primary_function(char *buf, int ret);
void				ft_found_error(char *str);

/*
** reader.c: read files from stdin and check for std errors
*/

void				ft_read(char *file);

#endif
