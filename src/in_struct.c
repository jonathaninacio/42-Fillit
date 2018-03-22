/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:40:28 by joinacio          #+#    #+#             */
/*   Updated: 2017/01/20 11:52:44 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

/*
** set all values of t_tetri
*/

void			in_s(t_tetri *tetri, int i, int j, char *c)
{
	tetri[i].coord[0].x = c[0] - 48;
	tetri[i].coord[0].y = c[1] - 48;
	tetri[i].coord[1].x = c[2] - 48;
	tetri[i].coord[1].y = c[3] - 48;
	tetri[i].coord[2].x = c[4] - 48;
	tetri[i].coord[2].y = c[5] - 48;
	tetri[i].coord[3].x = c[6] - 48;
	tetri[i].coord[3].y = c[7] - 48;
	tetri[i].top_x = c[8] - 48;
	tetri[i].top_y = c[9] - 48;
	tetri[i].index = i;
	tetri[i].totaloftetri = j;
}

/*
** sort all tetriminos and set them in the struct
*/

void			sort_tetri(char **str, int i, int j, t_tetri *tetri)
{
	if (ft_strstr(str[i], "#...#...#...#"))
		return (in_s(tetri, i, j, "0001020303"));
	if (ft_strstr(str[i], "####"))
		return (in_s(tetri, i, j, "0010203030"));
	if (ft_strstr(str[i], "##..#...#"))
		return (in_s(tetri, i, j, "0010010212"));
	if (ft_strstr(str[i], ".#...#..##"))
		return (in_s(tetri, i, j, "1011021212"));
	if (ft_strstr(str[i], "#...###"))
		return (in_s(tetri, i, j, "0001112121"));
	if (ft_strstr(str[i], "###...#"))
		return (in_s(tetri, i, j, "0010202121"));
	if (ft_strstr(str[i], ".#..###"))
		return (in_s(tetri, i, j, "1001112121"));
	if (ft_strstr(str[i], ".#..##...#"))
		return (in_s(tetri, i, j, "1001111212"));
	if (ft_strstr(str[i], "###..#"))
		return (in_s(tetri, i, j, "0010201121"));
	if (ft_strstr(str[i], "#...##..#."))
		return (in_s(tetri, i, j, "0001110212"));
	sort_tetri2(str, i, j, tetri);
}

void			sort_tetri2(char **str, int i, int j, t_tetri *tetri)
{
	if (ft_strstr(str[i], ".##.##."))
		return (in_s(tetri, i, j, "1020011121"));
	if (ft_strstr(str[i], "#...##...#"))
		return (in_s(tetri, i, j, "0001111212"));
	if (ft_strstr(str[i], "##...##"))
		return (in_s(tetri, i, j, "0010112121"));
	if (ft_strstr(str[i], ".#..##..#."))
		return (in_s(tetri, i, j, "1001110212"));
	if (ft_strstr(str[i], "##...#...#"))
		return (in_s(tetri, i, j, "0010111212"));
	if (ft_strstr(str[i], "#...#...##"))
		return (in_s(tetri, i, j, "0001021212"));
	if (ft_strstr(str[i], "..#.###"))
		return (in_s(tetri, i, j, "2001112121"));
	if (ft_strstr(str[i], "###.#.."))
		return (in_s(tetri, i, j, "0010200121"));
	if (ft_strstr(str[i], "##..##"))
		return (in_s(tetri, i, j, "0010011111"));
	else
	{
		ft_putstr("error\n");
		exit(1);
	}
}

/*
** Make a grid of the size of t_grid.size filled with dots
*/

t_grid			gridmaker(t_grid g, int a, int b)
{
	g.tab = malloc(sizeof(char*) * g.size + 1);
	while (a < g.size)
	{
		g.tab[a] = malloc(sizeof(char) * g.size + 1);
		while (b < g.size)
		{
			g.tab[a][b] = '.';
			b++;
		}
		g.tab[a][b] = '\0';
		b = 0;
		a++;
	}
	g.tab[a] = NULL;
	return (g);
}
