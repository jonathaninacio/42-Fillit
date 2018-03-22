/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joinacio <joinacio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:37:22 by joinacio          #+#    #+#             */
/*   Updated: 2016/11/22 18:10:30 by joinacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*zboub;

	if (!(zboub = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		zboub->content = NULL;
		zboub->content_size = 0;
		zboub->next = NULL;
		return (zboub);
	}
	if (!(zboub->content = malloc(sizeof(content_size))))
		return (NULL);
	if (zboub->content == NULL)
		return (NULL);
	zboub->content = ft_memcpy(zboub->content, content, content_size);
	zboub->content_size = content_size;
	zboub->next = NULL;
	return (zboub);
}
