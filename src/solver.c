/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:00:09 by joinacio          #+#    #+#             */
/*   Updated: 2017/01/16 19:12:00 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

void		inscoord(t_tetri t, t_grid g, int h, int l)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g.tab[t.coord[i].y + h][t.coord[i].x + l] = 'A' + t.index;
		i++;
	}
}

int			tstcoord(t_tetri t, t_grid g, int h, int l)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g.tab[t.coord[i].y + h][t.coord[i].x + l] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

int			mingrid(t_tetri *tetri, int a, int b)
{
	int		i;

	i = 0;
	while (a < tetri[0].totaloftetri)
	{
		if (tetri[a].top_x > b)
			b = tetri[a].top_x;
		if (tetri[a].top_y > b)
			b = tetri[a].top_y;
		a++;
	}
	if (tetri[0].totaloftetri == 1)
		i = 2;
	if (tetri[0].totaloftetri == 2)
		i = 3;
	if (tetri[0].totaloftetri == 3)
		i = 4;
	else
		while (i * i / 4 <= tetri[0].totaloftetri - 1)
			i++;
	if (b + 1 > i)
		i = b + 1;
	return (i);
}

int			solver(t_tetri *tetri, t_grid grid, int i)
{
	grid = printgrid(tetri, i, grid);
	while (i < tetri[0].totaloftetri)
	{
		while (!tstcoord(tetri[i], grid, grid.h, grid.l))
		{
			grid = increase_h(grid, tetri, i);
			if ((grid.h >= grid.size - (tetri[i].top_y)) && (i == 0))
				return (3);
			if (grid.h >= grid.size - (tetri[i].top_y))
				return (1);
			else
				grid.l++;
		}
		if (tstcoord(tetri[i], grid, grid.h, grid.l))
		{
			grid = tempgrid(grid, tetri, i);
			if (solver(tetri, grid, i + 1))
				grid = move_from_temp(grid);
			else
				return (0);
		}
	}
	return (0);
}

void		init_grid(t_tetri *tetri)
{
	t_grid	g;

	g.size = mingrid(tetri, 0, 0);
	g = gridmaker(g, 0, 0);
	g.l = 0;
	g.h = 0;
	g.index = 0;
	g.i = 0;
	while (solver(tetri, g, 0) == 3)
		g = bigger_grid(g);
}
