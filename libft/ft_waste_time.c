/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waste_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:01:19 by joinacio          #+#    #+#             */
/*   Updated: 2017/01/16 18:03:30 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_waste_time(int w)
{
	int z;
	int a;

	z = 0;
	a = 0;
	while (z != w)
	{
		while (a < 1000000)
		{
			ft_sqrt(100 * w);
			a++;
		}
		z++;
	}
}