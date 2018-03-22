/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_to_solve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:40:10 by joinacio          #+#    #+#             */
/*   Updated: 2017/01/16 19:11:11 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

/*
** create a temporary grid to stock the .tab grid.
*/

t_grid		tempgrid(t_grid grid, t_tetri *tetri, int i)
{
	grid.temp = (char **)malloc(sizeof(char*) * (grid.size + 1));
	grid.index = 0;
	while (grid.tab[grid.index] != NULL)
	{
		grid.temp[grid.index] = ft_strdup(grid.tab[grid.index]);
		grid.index++;
	}
	grid.temp[grid.index] = 0;
	inscoord(tetri[i], grid, grid.h, grid.l);
	return (grid);
}

/*
** print the grid in the std output and set grid.l and grid.h
*/

t_grid		printgrid(t_tetri *tetri, int i, t_grid grid)
{
	if (i == tetri[0].totaloftetri)
	{
		ft_puttab(grid.tab);
		exit(0);
	}
	grid.l = 0;
	grid.h = 0;
	return (grid);
}

/*
** move in the grid to the next coordinate
*/

t_grid		move_from_temp(t_grid grid)
{
	grid.tab = grid.temp;
	if (grid.l == grid.size)
	{
		grid.l = 0;
		grid.h++;
	}
	else
		grid.l++;
	return (grid);
}

/*
** reset grid.l and increase the value of grid.h
*/

t_grid		increase_h(t_grid grid, t_tetri *tetri, int i)
{
	if (grid.l >= grid.size - (tetri[i].top_x - 1))
	{
		grid.l = -1;
		grid.h++;
	}
	return (grid);
}

/*
** increase the size of the grid
*/

t_grid		bigger_grid(t_grid grid)
{
	grid.size++;
	grid = gridmaker(grid, 0, 0);
	return (grid);
}
