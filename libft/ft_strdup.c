/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:59:48 by joinacio          #+#    #+#             */
/*   Updated: 2016/11/15 09:25:27 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	z;
	size_t	i;
	char	*str;

	z = ft_strlen(s);
	if (!(str = (char*)malloc(sizeof(char) * z + 1)))
		return (NULL);
	i = 0;
	while (i < z)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
