/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:10:07 by svannest          #+#    #+#             */
/*   Updated: 2017/01/17 11:04:37 by svannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_tetri
{
	t_coord coord[4];
	int		index;
	int		totaloftetri;
	int		top_x;
	int		top_y;
}				t_tetri;

typedef struct	s_grid
{
	int		size;
	char	**tab;
	char	**temp;
	int		index;
	int		h;
	int		l;
	int		i;
}				t_grid;

char			*fic_in(char *av);

void			verif_taille_char(char *str);

int				linecounter(char *str, int i);

int				verif_norm(char *str, int i, int line);

void			cont_tetri(char *str);

void			insert_p(char *str);

void			clean_str(char *str);

void			say_check(char *newstr);

void			sort_tetri(char **str, int i, int j, t_tetri *tetri);

void			sort_tetri2(char **str, int i, int j, t_tetri *tetri);

void			in_s(t_tetri *tetri, int i, int j, char *c);

int				mingrid(t_tetri *tetri, int a, int b);

t_grid			gridmaker(t_grid g, int a, int b);

void			init_grid(t_tetri *tetri);

void			inscoord(t_tetri t, t_grid g, int x, int y);

int				tstcoord(t_tetri t, t_grid g, int x, int y);

int				solver(t_tetri *tetri, t_grid grid, int i);

t_grid			tempgrid(t_grid grid, t_tetri *tetri, int i);

t_grid			printgrid(t_tetri *tetri, int i, t_grid grid);

t_grid			move_from_temp(t_grid grid);

t_grid			increase_h(t_grid grid, t_tetri *tetri, int i);

t_grid			bigger_grid(t_grid grid);

#endif
