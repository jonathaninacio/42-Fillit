/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:17:48 by svannest          #+#    #+#             */
/*   Updated: 2017/01/16 10:46:36 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "tetriminos.h"

/*
** find all errors types.
*/

void		verif_taille_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
		{
			ft_putstr("error\n");
			exit(1);
		}
		i++;
	}
	if (i >= 546)
	{
		ft_putstr("error\n");
		exit(1);
	}
	if (verif_norm(str, 0, 0) == 1 || (str[0] == '\0'))
	{
		ft_putstr("error\n");
		exit(1);
	}
	insert_p(str);
}

/*
** Count the lines and characters.
*/

int			linecounter(char *str, int i)
{
	int x;

	x = 0;
	while (str[i] != '\n')
	{
		i++;
		x++;
	}
	if (x == 4)
		return (1);
	return (0);
}

/*
** Check all norm errors.
*/

int			verif_norm(char *str, int i, int line)
{
	while (str[i])
	{
		if (linecounter(str, i))
		{
			i = i + 5;
			line++;
		}
		else
			return (1);
		if (line > 4)
			return (1);
		if (str[i] == '\0')
			return (0);
		if ((line == 4 && str[i] == '\n' && str[i + 1] == '\n') ||
				(line == 4 && str[i + 1] == '\0'))
			return (1);
		if (line == 4 && str[i] == '\0')
			return (0);
		if (line == 4 && str[i] == '\n' && str[i + 1] != ('\0' | '\n'))
		{
			i++;
			line = 0;
		}
	}
	return (0);
}

void		cont_tetri(char *str)
{
	int		i;
	int		d;

	d = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != 'p' && str[i])
		{
			if (str[i] == '#')
				d++;
			i++;
		}
		if (d != 4)
		{
			ft_putstr("error\n");
			exit(1);
		}
		d = 0;
		if (str[i] == 'p')
			i++;
	}
	clean_str(str);
}

void		insert_p(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			str[i + 1] = 'p';
		i++;
	}
	cont_tetri(str);
}
