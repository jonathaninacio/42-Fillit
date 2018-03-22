/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:10:56 by joinacio          #+#    #+#             */
/*   Updated: 2016/11/21 18:29:35 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*s12;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(s12 = (char *)malloc(sizeof(char) * (len1 + len2))))
		return (NULL);
	len1 = 0;
	while (s1[len1])
	{
		s12[len1] = s1[len1];
		len1++;
	}
	len2 = 0;
	while (s2[len2])
	{
		s12[len1] = s2[len2];
		len1++;
		len2++;
	}
	s12[len1] = '\0';
	return (s12);
}
