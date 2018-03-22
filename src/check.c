/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 10:39:34 by svannest          #+#    #+#             */
/*   Updated: 2016/12/16 10:24:46 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

/*
** delete all the \n in the string and put \0 at the end of it
*/

void		clean_str(char *str)
{
	int		i;
	char	*newstr;
	int		j;

	newstr = ft_strdup(str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			i++;
		if (str[i] != '\n')
		{
			newstr[j] = str[i];
			i++;
			j++;
		}
	}
	while (j < i)
	{
		newstr[j] = '\0';
		j++;
	}
	say_check(newstr);
}

/*
** put all the tetri and their coordinates in a t_tetri*
*/

void		say_check(char *newstr)
{
	int		i;
	int		j;
	t_tetri *tetri;
	char	**tab;

	i = 0;
	j = 0;
	tab = ft_strsplit(newstr, 'p');
	while (tab[j])
		j++;
	tetri = (t_tetri *)malloc(sizeof(t_tetri) * j + 1);
	while (tab[i])
	{
		sort_tetri(tab, i, j, tetri);
		i++;
	}
	init_grid(tetri);
}
